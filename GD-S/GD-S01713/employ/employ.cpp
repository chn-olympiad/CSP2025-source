#include <bits/stdc++.h> 
using namespace std;
char s[501];
int f[501];
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,q=0,z=0;
	scanf("%d%d",&n,&m);
	long long p=1;
	for (int i=1;i<=n;i++)
	{
		scanf(" %c",&s[i]);
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
		if (f[i]==0)
		f[i]=1;
	}
	sort(f+1,f+1+n,cmp);
	for (int i=1;i<=n;i++)
	{
		if (f[i]<=q)
		{
			q++;
			continue;
		}
		if (s[i]=='0')
		q++;
		if (s[i]=='1')
		z++;
	}
	if (z<m)
	printf("0");
	else 
	{
		for (int i=1,k=1;i<n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				if (f[i]==f[j])
				k++;
				else 
				{
					i=j-1;
					break;
				}
			}
			if (k!=1)
			{
				while (k>1)
				{
					p=p*k%998244353;
					k--;
				}
			}
		}
		printf("%lld",p);
	}
	return 0;
}
