#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define N 1010
using namespace std;
inline long long read()
{
	long long x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,m,a[N],ans[N][N];
int cmp(int a,int b)
{
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n*m;i++) a[i]=read();
	int x=a[1],k=0;
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j++)
	{
		if(j%2==1) for(int i=1;i<=n;i++) ans[i][j]=a[++k];
		else for(int i=n;i>=1;i--) ans[i][j]=a[++k];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ans[i][j]==x)
			{
				printf("%lld %lld",j,i);
				return 0;
			}
		}
	}
	return 0;
}

