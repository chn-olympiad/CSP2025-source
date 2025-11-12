#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[10086],s,as;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==m)
		{
			a[i]=-1;
			as++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=-1)
		{
			s=a[i];
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]!=-1)
				{
					s^=a[j];
					if(s==m)
					{
						for(int k=i;k<=j;k++) a[k]=-1;
						as++;
						s=-1;
						j=n;
					}
				}
				if(a[j]==-1) j=n;
			}
		}
	}
	printf("%lld",as);
	return 0;
}
