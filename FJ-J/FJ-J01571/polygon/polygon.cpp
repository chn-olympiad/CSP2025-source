#include<bits/stdc++.h>
using namespace std;
long long a[5005],ans=0,m=0,v[50005],n;
void dfs(long long o,long long z,long long c,long long p)
{
	for(int f=z;f<o;f++)
	{
		if(v[f]==0)
		{
			v[f]=1;
			dfs(o,f+1,c+a[f],p+1);
			v[f]=0;
		}
	}
	if(p>=2&&c>a[o])
	{

		ans++;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		
		dfs(i,1,0,0);
			
		
	}
	cout<<ans;
	return 0;
}
