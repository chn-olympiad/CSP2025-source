#include<cstdio> 
using namespace std;
int n,k,a[500001],rb[2][500001],r=1,l,g,ans;
bool lock[500001];
int xor1(int a,int b)
{
	return (a&(!b))|((!a)&b);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n-i;j++)
		{
			if(i==1)
			{
				if(a[j]==k)
				{
					ans++;
					lock[j]=true; 
				}
				continue;
			}
			if(i==2)
			{
				if(lock[j])
				{
					rb[l][j]=-1;
					continue;
				}
				if(lock[j+1])
				{
					rb[l][j]=-1;
					continue;
				}
				rb[l][j]=xor1(a[j],a[j+i-1]);
				continue;
		    }
		    if(lock[j])
			{
				rb[l][j]=-1;
				continue;
			}
			for(int k1=0;k1<i;k1++)
			{
				if(lock[j+k1])
				{
					rb[l][j]=-1;
					continue;
				}
			}
			rb[l][j]=xor1(rb[r][j],a[j+i-1]);
		}
		if(i==1)
		    continue;
		for(int j=0;j<=n-i;j++)
		{
			if(rb[l][j]==k)
			{
				ans++;
				for(int k1=0;k1<i;k1++)
				{
					lock[j+k1]=true;
				}
			}
		}
		g=r;
		r=l;
		l=g;
	}
	printf("%d",ans);
	return 0;
}
