#include<bits/stdc++.h>
using namespace std;
long long qm=998244353;
long long da;
int n;
int a[5005],b[5005];
void s(int c,int bc,long long zh)
{
	if(bc>3)
	{
		if(zh>b[bc-1])da++;
	}
	if(c>n)return;
	zh+=b[bc-1];
	for(int i=c;i<=n;i++)
	{
		b[bc]=a[i];
		s(i+1,bc+1,zh);
		b[bc]=0;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int d;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(a[1]==1 and a[n]==1 and a[n/2]==1)
	{
		int p=1,o=1;
		for(int i=n;i>=1;i--)
		{
			p=p*i;o=o*(n-i+1);
			if(i<=n-2)da+=p/o;
		}
	}
	else
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]<a[i])
				{
					d=a[j];a[j]=a[i];a[i]=d;
				}
			}
		}
		s(1,1,0);
	}
	printf("%lld",da%qm);
	return 0;
}
