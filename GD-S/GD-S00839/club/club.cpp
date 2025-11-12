#include<bits/stdc++.h>
using namespace std;
const int maxn=220;
int t;
int n;
struct node{
	int a[4];
}d[maxn];
bool cmp1(node& a,node& b){
	return a.a[1]>b.a[1];
}
int ans;
void solve1(){
	ans=0;
	sort(d+1,d+n+1,cmp1);
	for(int i=1;i<=n/2;i++)ans+=d[i].a[1];
	cout<<ans<<" ";
	return;
}
bool cmp2(node& a,node& b){
	return a.a[1]-a.a[2]>b.a[1]-b.a[2];
}
int dp[maxn][220][220];
void solve2(){
	ans=0;
	sort(d+1,d+n+1,cmp1);
	for(int i=1;i<=n;i++){
		for(int a=0;a<=i&&a<=n/2;a++){
			for(int b=0;a+b<=i&&b<=n/2;b++){
				dp[i][a][b]=max((a>0?dp[i-1][a-1][b]+d[i].a[1]:0),(b>0?dp[i-1][a][b-1]+d[i].a[2]:0));
				ans=max(ans,dp[i][a][b]);
			}
		}
	}
	cout<<ans<<"\n";
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		bool f1=true,f2=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>d[i].a[j];
			}
			if(d[i].a[2]!=0||d[i].a[3]!=0)f1=false;
			if(d[i].a[3]!=0)f2=false;
		}
		ans=0;
		if(f1){
			solve1();
			continue; 
		}else if(f2){
			solve2();
			continue;
		}
		for(int a=0;a<=n/2;a++){
			for(int b=0;b<=n/2;b++){
				dp[0][a][b]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int a=0;a<=i&&a<=n/2;a++){
				for(int b=0;a+b<=i&&b<=n/2;b++){
					int c=i-a-b;
					dp[i][a][b]=max((a>0?dp[i-1][a-1][b]+d[i].a[1]:0),max((b>0?dp[i-1][a][b-1]+d[i].a[2]:0),max((c>0?dp[i-1][a][b]+d[i].a[3]:0),dp[i-1][a][b])));
					ans=max(ans,dp[i][a][b]);
				}
			}
		}
		/*for(int a=0;a<=n/2;a++){
			for(int b=0;b<=n/2;b++){
				//cerr<<dp[n][a][b]<<" ";
				ans=max(ans,dp[n][a][b]);
			}
			//cerr<<"\n";
		}*/
		//cerr<<"\n";
		cout<<ans<<"\n";
	}//rp ++
	return 0;
} 

