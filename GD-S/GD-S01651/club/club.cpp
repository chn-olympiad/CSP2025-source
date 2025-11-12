#include<bits/stdc++.h>
using namespace std;
const long long MAXN=210100;
long long n,a[MAXN][4],cnt[4],mindec[MAXN],M,sum;
long long chkmax(long long x)
{
	if(a[x][1]>=a[x][2]&&a[x][1]>=a[x][3])
	{
		return 1;
	}
	if(a[x][2]>=a[x][3]&&a[x][2]>=a[x][1])
	{
		return 2;
	}
	if(a[x][3]>=a[x][1]&&a[x][3]>=a[x][2])
	{
		return 3;
	}
	return 0;
}
long long calc(long long x)
{
	if(a[x][1]>=a[x][2]&&a[x][1]>=a[x][3])
	{
		return min(a[x][1]-a[x][2],a[x][1]-a[x][3]);
	}
	if(a[x][2]>=a[x][3]&&a[x][2]>=a[x][1])
	{
		return min(a[x][2]-a[x][3],a[x][2]-a[x][1]);
	}
	if(a[x][3]>=a[x][1]&&a[x][3]>=a[x][2])
	{
		return min(a[x][3]-a[x][1],a[x][3]-a[x][2]);
	}
	return 0;
}
long long cntmax()
{
	if(cnt[1]>=cnt[2]&&cnt[1]>=cnt[3])
	{
		return 1;
	}
	if(cnt[2]>=cnt[3]&&cnt[2]>=cnt[1])
	{
		return 2;
	}
	if(cnt[3]>=cnt[1]&&cnt[3]>=cnt[2])
	{
		return 3;
	}
	return 0;
}
long long tmax(long long ta,long long tb,long long tc)
{
	return max(max(ta,tb),tc);
}
void read(long long &x)
{
	x=0;
	char c=getchar();
	while(!((c>='0')&&(c<='9')))
	{
		c=getchar();
	}
	while((c>='0')&&(c<='9'))
	{
		x=x*10+c-48;
		c=getchar();
	}
	return;
}
void work()
{
	long long i,j;
//	scanf("%lld",&n);
	read(n);
	cnt[1]=cnt[2]=cnt[3]=0;
	sum=0;
	for(i=1;i<=n;i++)
	{
//		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		read(a[i][1]),read(a[i][2]),read(a[i][3]);
		cnt[chkmax(i)]++;
		sum+=tmax(a[i][1],a[i][2],a[i][3]);
	}
	long long lim=(n/2)+1,pos=0;
	M=0;
	if(tmax(cnt[1],cnt[2],cnt[3])>=lim)
	{
		pos=cntmax();
		for(i=1;i<=n;i++)
		{
			if(chkmax(i)==pos)
			{
				M++;
				mindec[M]=calc(i);
			}
		}
		sort(mindec+1,mindec+1+M);
		for(i=1;cnt[pos]>=lim;i++)
		{
			cnt[pos]--;
			sum-=mindec[i];
		}
	}
	printf("%lld\n",sum);
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long T;
//	scanf("%lld",&T);
	read(T);
	while(T--)
	{
		work();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
