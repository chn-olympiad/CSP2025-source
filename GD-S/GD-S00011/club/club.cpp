#include<bits/stdc++.h>
using namespace std;
long long cnt=0;
long long a[5001][4],vis[31][31][31];
void dfs(int a1,int a2,int a3,int en,long long ans,int w)
{
	if(a1>en/2||a2>en/2||a3>en/2) return ;
	if(w==en)
	{	
//			cout<<ans<<endl;
			
			cnt=max(cnt,ans);
			return ;
	}
	dfs(a1+1,a2,a3,en,ans+a[w+1][1],w+1);
	dfs(a1,a2+1,a3,en,ans+a[w+1][2],w+1);
	dfs(a1,a2,a3+1,en,ans+a[w+1][3],w+1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
			int n;
			cin>>n;
			for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
			dfs(0,0,0,n,0,0);
			cout<<cnt<<endl;
			cnt=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
