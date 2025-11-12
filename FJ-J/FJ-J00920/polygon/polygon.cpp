#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,ans=0,g,p,v[N],x=1,c=0;
int a[N];
void dfs(int u)
{
	if(c==p)
	{
		if(ceil(g*1.0/2)>a[u])
		ans++;
		ans%=998244353;
		return;
	}
	for(int j=x;j<=n;j++)
	{
		if(!v[j])
		{
			v[j]=1;
			g+=a[j];
			c++;
			int t=x;
			x=j+1;
			dfs(j);
			x=t;
			c--;
			g-=a[j];
			v[j]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		p=i;
		dfs(0);
	}
	cout<<ans<<endl;
	return 0;
}
