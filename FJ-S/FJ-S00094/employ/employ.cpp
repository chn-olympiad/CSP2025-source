#include<bits/stdc++.h>
using namespace std;
int n,m,s[505],c[505];
long long ans=0,mod=998244353;
bool pd[505];
void dfs(int x,int y)
{
	if(n-y<m)
	return;
	if(x==n)
	{
		if(n-y>=m)
		ans++;
		else
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!pd[i])
		{
			pd[i]=true;
			if(s[x+1]==0||y>=c[i])
			dfs(x+1,y+1);
			else
			dfs(x+1,y);
			pd[i]=false;
		}
	}
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	char cc;
    	cin>>cc;
    	s[i]=int(cc-'0');
	}
	for(int i=1;i<=n;i++)
	cin>>c[i];
	dfs(0,0);
	cout<<ans;
    return 0;
}
