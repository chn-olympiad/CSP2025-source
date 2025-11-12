#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,k;
int T;
struct node{
	int a,b,c;
	int ia,ib,ic;
}f[N];
bool cmp(node a,node b){
	return a.a>b.a;
}
int mx;
void dfs(int x,int sum,int a,int b,int c){
	if(x==n+1){
		mx=max(mx,sum);
		return;
	}
	if(a<n/2)dfs(x+1,sum+f[x].a,a+1,b,c);
	if(b<n/2)dfs(x+1,sum+f[x].b,a,b+1,c);
	if(c<n/2)dfs(x+1,sum+f[x].c,a,b,c+1);
}
int num[4];
int flag0,flag1;
long long dp[205][205][205];
long long pd[205][205];
signed main(){
	//ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		flag0=1,flag1=1;
		for(int i=1;i<=3;i++)num[i]=0;
		for(int i=1;i<=n;i++){
			cin>>f[i].a>>f[i].b>>f[i].c;
			if(f[i].c!=0)flag0=0,flag1=0;
			if(f[i].b!=0)flag0=0;
		}
		long long ans=0;
		if(n<30){
			mx=0;
			dfs(1,0,0,0,0);
			cout<<mx<<'\n';
			continue;
		}
		if(flag0){
			sort(f+1,f+1+n,cmp);
			for(int i=1;i<=n/2;i++)ans+=f[i].a;
			cout<<ans<<'\n';
			continue;
		}
		if(flag1){
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					if(i+j>n)break;
					pd[i][j]=0;
					if(i)pd[i][j]=max(pd[i][j],pd[i-1][j]+f[i+j].a);
					if(j)pd[i][j]=max(pd[i][j],pd[i][j-1]+f[i+j].b);
					if(i+j==n)ans=max(ans,pd[i][j]);
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					if(i+j+k>n)break;
					dp[i][j][k]=0;
					if(i)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+f[i+j+k].a);
					if(j)dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+f[i+j+k].b);
					if(k)dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+f[i+j+k].c);
					if(i+j+k==n)ans=max(ans,dp[i][j][k]);
				}
			}
		}
		cout<<ans<<'\n';
	}
}
