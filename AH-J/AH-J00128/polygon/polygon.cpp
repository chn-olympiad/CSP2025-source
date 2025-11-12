#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,a[N],cnt;
bool f[N];
void dfs(int x,int ans,int maxn)
{
	maxn=max(maxn,a[x]);
	if(ans>2*maxn)
	{
		cnt+=n-x+1;
		return ;
	}
	for(int i=x+1;i<=n;i++)
	{
		if(!f[i])
		{
						f[i]=1;
			dfs(i,ans+a[i],max(maxn,a[i]));
			f[i]=0;
		}
	}
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
		f[i]=1;
		dfs(i,a[i],a[i]);
	}
	cout<<cnt;
    return 0;
}
