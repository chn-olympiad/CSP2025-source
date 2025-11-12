#include <bits/stdc++.h>
using namespace std;
int s[5001];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,z=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
	}
	sort(s+1,s+1+n,cmp);
	for (int i=1;i<=n-2;i++)
	{
		for (int j=i+1;j<=n-1;j++)
		{
			for (int k=j+1;k<=n;k++)
			{
				if (s[i]<s[j]+s[k])
				z++;
				for (int l=k+1;l<=n;l++)
				{
					if (s[i]<s[j]+s[l])
					z++;
					if (s[i]<s[k]+s[l])
					z++;
					if (s[i]<s[j]+s[k]+s[l])
					z++;
					for (int p=l+1;i<=n;p++)
					{
						if (s[i]<s[j]+s[p])
						z++;
						if (s[i]<s[k]+s[p])
						z++;
						if (s[i]<s[l]+s[p])
						z++;
						if (s[i]<s[j]+s[k]+s[p])
						z++;
						if (s[i]<s[j]+s[l]+s[p])
						z++;
						if (s[i]<s[j]+s[k]+s[l]+s[p])
						z++;
					}
				}
			}
		}
	}
	printf("%d",z);
	return 0;
}
