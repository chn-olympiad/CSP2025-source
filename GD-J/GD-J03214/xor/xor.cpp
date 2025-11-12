#include<bits/stdc++.h>
using namespace std;
int a[500005],s[500005],f[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,x;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		for(int j=i-1;j>=1;j--)
		{
			if((s[j-1]^s[i])==k)
			{
				f[i]=max(f[i],f[j-1]+1);
				break;
			}
		}
		if(a[i]==k)
		{
			f[i]=max(f[i],f[i-1]+1);
		}
	}
	cout<<f[n];
}
