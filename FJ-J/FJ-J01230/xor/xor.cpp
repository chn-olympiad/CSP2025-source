#include<bits/stdc++.h>
using namespace std;
int n,k,l,a[526000],b[526000],t,f[526000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	l=0;
	for(int i=1;i<=n;i++)
	{
		t=a[i];
		if(t==k)
		{
			l=i;
			b[i]=i;
		}
		for(int j=i-1;j>l;j--)
		{

			t=t^a[j];
			if(t==k)
			{
				l=j;
				b[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			f[i]=f[i-1];
		}
		else
		{
			f[i]=max(f[i-1],f[b[i]-1]+1);
		}
	}
	cout<<f[n];
}





















