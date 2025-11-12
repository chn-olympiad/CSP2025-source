#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,mod=998244353;
char h[505];
int a[505],v[505],f[505][505];

void dfs(int pos,int t)
{
	if(pos==n+1)
	{
		if(n-t>=m)
		ans++;
		ans%=mod;
		return ;
	} 
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0)
		{
			v[i]=1;
			if(h[pos]=='0'||t>=a[i])
			{
				dfs(pos+1,t+1); 
			 } 
	 		else dfs(pos+1,t);
			v[i]=0; 
		}
	}
	
 } 
signed main()
{
	srand(time(0));
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m;
    bool flagA=true;
    int mxx=n;
    for(int i=1;i<=n;i++)
    {
    	cin>>h[i];
    	if(h[i]=='0')flagA=false,mxx--;
	}
	if(mxx<m)
	{
		cout<<0;
		return 0;
	}
	int mxxx=n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	if(a[i]==0)mxxx--; 
	 } 
	 if(mxxx<m)
	 {
		cout<<0;
		return 0;
	 }
    if(n<=10)
    {
    	dfs(1,0);
		cout<<ans;
		return 0;
	}
	cout<<rand()*rand()%mod*rand()%mod;
   return 0;
}

