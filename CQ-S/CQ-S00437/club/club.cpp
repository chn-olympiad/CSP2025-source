#include<bits/stdc++.h>
using namespace std;
int T;
int n;
const int N=1e5+10;
struct node{
	int a,b,c;
}s[N];
long long dp[210][210][210];
//int flag=2;
vector<node>a,b,c;
long long ans[N];
bool cmp(long long x,long long y){return x>y;}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b>>s[i].c;
	} 
	if(n<=200){
		for(int i=1;i<=n;i++)for(int j=0;j<=n;j++)for(int k=0;k<=n;k++)dp[i][j][k]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=min(i,n/2);j++){
				for(int k=0;k<=min(i-j,n/2);k++){
					if(i-j-k>n/2)dp[i][j][k]=-0x7f7f7f7f;
					else{
						if(i-j-k>0)dp[i][j][k]=dp[i-1][j][k]+s[i].c;
						if(j>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+s[i].a);
						if(k>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+s[i].b);
					}
				}
			}
		}
		long long ans=0;
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n-j;k++){
				ans=max(ans,dp[n][j][k]);
			}
		}
		cout<<ans<<"\n";
	}else{
		long long ansn=0,tot=0;
		a.clear(),b.clear(),c.clear();
		for(int i=1;i<=n;i++){
			if(s[i].a>=s[i].b&&s[i].a>=s[i].c)a.push_back(s[i]),ansn+=s[i].a;
			else if(s[i].b>=s[i].a&&s[i].b>=s[i].c)b.push_back(s[i]),ansn+=s[i].b;
			else if(s[i].c>=s[i].a&&s[i].c>=s[i].b)c.push_back(s[i]),ansn+=s[i].c;
		}
		if((int)a.size()>n/2){
			tot=0;
			for(int i=0;i<(int)a.size();i++){
				ans[++tot]=max(a[i].b,a[i].c)-a[i].a;
			}
			sort(ans+1,ans+tot+1,cmp);
			for(int i=1;i<=(int)a.size()-n/2;i++)ansn+=ans[i];
		}
		else if((int)b.size()>n/2){
			tot=0;
			for(int i=0;i<(int)b.size();i++){
				ans[++tot]=max(b[i].a,b[i].c)-b[i].b;
			}
			sort(ans+1,ans+tot+1,cmp);
			for(int i=1;i<=(int)b.size()-n/2;i++)ansn+=ans[i];
		}else if((int)c.size()>n/2){
			tot=0;
			for(int i=0;i<(int)c.size();i++){
				ans[++tot]=max(c[i].a,c[i].b)-c[i].c;
			}
			sort(ans+1,ans+tot+1,cmp);
			for(int i=1;i<=(int)c.size()-n/2;i++)ansn+=ans[i];
			
		}
		cout<<ansn<<"\n";
	}
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)solve();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

