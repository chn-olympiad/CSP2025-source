#include<bits/stdc++.h>
using namespace std;
int a[4][100005];
int b[100005];
int c[4];
int maxx;
bool cmp(int x,int y)
{
	return x>y;
}
void fun(int k,int n,int m,int s)
{
	if(k==n+1)
	{
		maxx=max(s,maxx);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(c[i]<m)
		{
			s+=a[i][k];
			c[i]+=1;
			fun(k+1,n,m,s);
			s-=a[i][k];
			c[i]-=1;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int z=1;z<=t;z++)
	{
		int n;
		scanf("%d",&n);
		long long mun=0;
		int m=n/2;
		bool f=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[1][i],&a[2][i],&a[3][i]);
			if(!(a[2][i]==0&&a[3][i]==0))
			{
				f=0;
			}
			b[i]=a[1][i];
		}
		if(f==1)
		{
			sort(b+1,b+1+n,cmp);
			for(int i=1;i<=m;i++)
			{
				mun+=b[i];
			}
			printf("%lld\n",mun);
			continue;
		}
		maxx=0;
		fun(1,n,m,0);
		printf("%d\n",maxx);
	}
	return 0;
}
