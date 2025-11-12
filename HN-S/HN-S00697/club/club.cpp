#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
long long max(long long a,long long b){return (a>b?a:b);}
const int N=(1e+5)+5;
int n,n2;
long long a[N][3],f[2][205][205];
bool flag1,flag2;

void init()
{
	flag1=flag2=true;
	scanf("%d",&n); n2=(n<<1);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
		if(a[i][1]>0) flag1=false;
		if(a[i][2]>0) flag2=false;
	}
}

void DP()
{
	int q,p;
	long long ans=0;
	memset(f,-1,sizeof(f));f[0][0][0]=0;
	for(int i=0;i<n;i++)
	{
		p=(i&1); q=(1-p);
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=n;k++)
			{
				if(f[p][j][k]==-1) continue;
				f[q][j+1][k]=max(f[q][j+1][k],f[p][j][k]+a[i+1][0]);
				f[q][j][k+1]=max(f[q][j][k+1],f[p][j][k]+a[i+1][1]);
				f[q][j][k]=max(f[q][j][k],f[p][j][k]+a[i+1][2]);
			}
		}
		memset(f[p],-1,sizeof(f[p]));
	}
	for(int i=0;i<=(n>>1);i++)
		for(int j=(n>>1)-i;j<=(n>>1);j++)
			ans=max(ans,f[n&1][i][j]);
	printf("%lld\n",ans);
	return;
}

bool cmp(int x,int y)
{
	return a[x][0]>a[y][0];
}

void calc1()
{
	int id[N];
	long long ans=0;
	for(int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<=(n>>1);i++) ans+=a[id[i]][0];
	cout<<ans<<endl;
}

bool cmp1(int x,int y)
{
	return a[x][0]-a[x][1]>a[y][0]-a[y][1];
}

bool cmp2(int x,int y)
{
	return a[x][1]-a[x][0]>a[y][1]-a[y][0];
}

void calc2()
{
	int s[2][N],top[2];
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i][0]>a[i][1]){top[0]++;s[0][top[0]]=i;}
		else {top[1]++;s[1][top[1]]=i;}
	}
	if(top[0]>(n>>1))
	{
		sort(s[0]+1,s[0]+top[0]+1,cmp1);
		while(top[0]>(n>>1))
		{
			top[1]++; s[1][top[1]]=s[0][top[0]]; top[0]--;
		}
	}
	else
	{
		sort(s[1]+1,s[1]+top[1]+1,cmp2);
		while(top[1]>(n>>1))
		{
			top[0]++; s[0][top[0]]=s[1][top[1]]; top[1]--;
		}
	}
	for(int i=1;i<=top[0];i++) ans+=a[s[0][i]][0];
	for(int i=1;i<=top[1];i++) ans+=a[s[1][i]][1];
	cout<<ans<<endl;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while (T--)
	{
		init();
		if(n<=200) DP();
		else if(flag1) calc1();
		else if(flag2) calc2();
	}
	return 0;
}

