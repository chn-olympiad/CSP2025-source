#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int Q,n,maxn=-1,dp[205][205][205];
int x[N],y[N],z[N];
struct as{
	int u,v,val;
}d[N];
void solve(){
	int sum=0;
	sort(x+1,x+n+1);
	for(int i=n;i>=n/2+1;i--) sum+=x[i];
	cout<<sum<<"\n";
}
bool cmp(as a,as b){
	return a.val<b.val;
}
void solve1(){
	int sum=0;
	for(int i=1;i<=n;i++){
		d[i].val=x[i]-y[i];
		d[i].u=x[i],d[i].v=y[i];
	}
	sort(d+1,d+n+1,cmp);
	for(int i=1;i<=n/2;i++) sum+=d[i].v;
	for(int i=n/2+1;i<=n;i++) sum+=d[i].u;
	cout<<sum<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>Q;
	while(Q--){
		maxn=-1;
		memset(dp,0,sizeof(dp));
		cin>>n;
		bool flag=0,flag1=0;
		for(int i=1;i<=n;i++){
			cin>>x[i]>>y[i]>>z[i];
			if(y[i]) flag=1;
			if(z[i]) flag1=1;
		}
		if(flag==0&&flag1==0){
			solve();
			continue;
		}
		if(flag&&flag1==0){
			solve1();
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n-j;k++){
					int c=n-j-k;
					if(c<0) break;
					if(j>0) dp[i][j][k]=max(dp[i-1][j-1][k]+x[i],dp[i][j][k]);
					if(k>0) dp[i][j][k]=max(dp[i-1][j][k-1]+y[i],dp[i][j][k]);
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+z[i]);
				}
			}
		}
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				maxn=max(maxn,dp[n][i][j]);
			}
		}
		cout<<maxn<<"\n";		
	}
}
