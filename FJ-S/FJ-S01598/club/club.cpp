#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T;
int n;
int sum[4],ans=0;
struct node{
	int a,b,c;
	int maxn;
}st[N];
int x[10000][10000];
int dp[N];
int k=0,kk=0;
bool cmpa(node x,node y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		int i,j;
		ans=0;
		cin>>n;
		if(n==2){
			for(i=1;i<=n;i++){
				for(j=1;j<=3;j++){
					cin>>x[i][j];
				}
			}
			int maxn=-1;
			for(i=1;i<=3;i++){
				ans=x[1][i];
				for(j=1;j<=3;j++){
					if(i!=j) ans+=x[2][j];
					maxn=max(maxn,ans);
					ans=x[1][i];				
				}
			}
			cout<<maxn<<endl;
			continue;
		}
		for(i=1;i<=n;i++){
			cin>>st[i].a>>st[i].b>>st[i].c;
			if(st[i].b!=0) k=1;
			if(st[i].c!=0) kk=1;
		}
		//if(k==0&&kk==0){
			sort(st+1,st+1+n,cmpa);
			for(i=1;i<=n/2;i++) ans+=st[i].a;
			cout<<ans<<endl;
			continue;
		//}
//		else{
//			for(i=1;i<=n;i++){
//				for(j=1;j<=3;j++){
//					cin>>x[i][j];
//				}
//			}			
//			for(i=1;i<=n;i++){
//				for(j=1;j<=3;j++){
//					if(sum[i]+1<=n/2){
//						dp[i]=max(dp[i],dp[i-1]+x[i][j]);
//						sum[i]++;
//					}
//				}
//			}
//		}
//		cout<<dp[n]<<endl;
	}
	return 0;
}

