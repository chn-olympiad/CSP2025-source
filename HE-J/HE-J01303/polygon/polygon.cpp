#include <bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans=0;
void DFS(int c,int *b,int d)
{
	for(int i=d;i<n-c;i++)
	{
		if(c==-1)
		{
			int z=0,maxx=0;
			for(int j=0;j<d;j++)
			{
				z+=a[b[j]];
				maxx=max(maxx,a[b[j]]);
			}
			if(z>maxx*2) ans++;
		}
		else
		{
			b[c]=i;
			DFS(c--,b,d++);
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<n;i++)
	{
		int b[i];
		DFS(i,b,0);
	} 
	cout<<ans%998244353;
	return 0;
}
