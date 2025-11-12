#include<bits/stdc++.h>
using namespace std;
int n,k,w[500005];
int a[500005],f[500005];
int e[5000005],s[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n	,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	e[0]=1;
	for(int i=1;i<=n;i++)
	{
		int q=k^s[i];
		if(a[i]==k)
		{
			w[i]=i;
		}
		else if(e[q])
		{
			w[i]=e[q];
		}
		else
			w[i]=-1;
		e[s[i]]=i+1;
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		if(w[i]!=-1)
		{
			f[i]=max(f[i],f[w[i]-1]+1);
		}
	}
	printf("%d",f[n]);
	return 0;
}
