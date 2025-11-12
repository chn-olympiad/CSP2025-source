#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int N=105,Md=998244353;
int n,m,c[N],txt;
long long f[N][N][N],l[N][N][N];
char a[N];
bool flag1;

bool cmp(int a,int b)
{
	return a<b;
}

void init()
{
	flag1=true;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]<'0' || a[i]>'1') i--;
		if(a[i]=='0') flag1=false;
		if(a[i]=='1') txt++;
	}
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	sort(c+1,c+n+1,cmp);
}

long long jiec(int n)
{
	long long ans=1;
	for(int i=1;i<=n;i++) ans=ans*i%Md;
	return ans;
}

void calc2()
{
	long long ans=0;
	for(int i=0;i<=(1<<n)-1;i++)
	{
		int num=0;
		for(int j=i,x=1;j>0;j=(j>>1),x++)
		{
			if(a[x]=='1' && (j&1)) num++;
		}
		if(num>=m) ans++;
	}
	printf("%lld",ans);
}

void calc1()
{
	printf("%lld",jiec(n));
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	init();
	if(flag1) calc1();
	else if(txt<m) printf("0\n");
	else calc2();
	return 0;
}
