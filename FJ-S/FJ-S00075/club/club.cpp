#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int a[N][4];
int e[4][N];
int tp1=0,tp2=0,tp3=0;
long long ans=0;
int n;
bool cmp1(int x,int y)
{
	int rx=max(a[x][2],a[x][3])-a[x][1];
	int ry=max(a[y][2],a[y][3])-a[y][1];
	
	return rx<ry;
}

bool cmp2(int x,int y)
{
	int rx=max(a[x][1],a[x][3])-a[x][2];
	int ry=max(a[y][1],a[y][3])-a[y][2];
	
	return rx<ry;
}

bool cmp3(int x,int y)
{
	int rx=max(a[x][2],a[x][1])-a[x][3];
	int ry=max(a[y][2],a[y][1])-a[y][3];
	
	return rx<ry;
}
void solve()
{
	tp1=tp2=tp3=0;
	ans=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		if (a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
		{
			e[1][++tp1]=i;
		}
		else if (a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
		{
			e[2][++tp2]=i;
		}
		else
		{
			e[3][++tp3]=i;
		}
	}
	
	if (tp1>n/2)
	{
		sort(e[1]+1,e[1]+tp1+1,cmp1);
		while (tp1>n/2)
		{
			if (a[e[1][tp1]][2]>=a[e[1][tp1]][3])
			{
				e[2][++tp2]=e[1][tp1--];
			}
			else
			{
				e[3][++tp3]=e[1][tp1--];
			}
		}
		
		for (int i=1;i<=tp1;i++)
		{
			ans+=a[e[1][i]][1];
		}
		for (int i=1;i<=tp2;i++)
		{
			ans+=a[e[2][i]][2];
		}
		for (int i=1;i<=tp3;i++)
		{
			ans+=a[e[3][i]][3];
		}
		printf("%lld\n",ans);
		return ;
	}
	
	if (tp2>n/2)
	{
		sort(e[2]+1,e[2]+tp2+1,cmp2);
		while (tp2>n/2)
		{
			if (a[e[2][tp2]][1]>=a[e[2][tp2]][3])
			{
				e[1][++tp1]=e[2][tp2--];
			}
			else
			{
				e[3][++tp3]=e[2][tp2--];
			}
		}
		
		for (int i=1;i<=tp1;i++)
		{
			ans+=a[e[1][i]][1];
		}
		for (int i=1;i<=tp2;i++)
		{
			ans+=a[e[2][i]][2];
		}
		for (int i=1;i<=tp3;i++)
		{
			ans+=a[e[3][i]][3];
		}
		printf("%lld\n",ans);
		return ;
	}
	
	if (tp3>n/2)
	{
		sort(e[3]+1,e[3]+tp3+1,cmp3);
		while (tp3>n/2)
		{
			if (a[e[3][tp3]][2]>=a[e[3][tp3]][1])
			{
				e[2][++tp2]=e[3][tp3--];
			}
			else
			{
				e[1][++tp1]=e[3][tp3--];
			}
		}
		
		for (int i=1;i<=tp1;i++)
		{
			ans+=a[e[1][i]][1];
		}
		for (int i=1;i<=tp2;i++)
		{
			ans+=a[e[2][i]][2];
		}
		for (int i=1;i<=tp3;i++)
		{
			ans+=a[e[3][i]][3];
		}
		printf("%lld\n",ans);
		return ;
	}
	
	for (int i=1;i<=tp1;i++)
	{
		ans+=a[e[1][i]][1];
	}
	for (int i=1;i<=tp2;i++)
	{
		ans+=a[e[2][i]][2];
	}
	for (int i=1;i<=tp3;i++)
	{
		ans+=a[e[3][i]][3];
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while (T--)
	{
		solve();
	}
	return 0;
}
