#include<bits/stdc++.h>
using namespace std;

const int N=165,N2=85;
int t,n;
int a[N][4];
int ans;
int vis[N][N2][N2][N2];

int dfs(int k,int n1,int n2,int n3)
{
	if((n1>n/2)||(n2>n/2)||(n3>n/2)) return -1e8;
	if(k>n) return 0;
	if(vis[k][n1][n2][n3]!=-1) return vis[k][n1][n2][n3];
	int dfs1,dfs2,dfs3;
	dfs1=dfs(k+1,n1+1,n2,n3)+a[k][1];
	dfs2=dfs(k+1,n1,n2+1,n3)+a[k][2];
	dfs3=dfs(k+1,n1,n2,n3+1)+a[k][3];
	return vis[k][n1][n2][n3]=max(dfs1,max(dfs2,dfs3));
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		memset(vis,-1,sizeof vis);
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		ans=dfs(1,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
