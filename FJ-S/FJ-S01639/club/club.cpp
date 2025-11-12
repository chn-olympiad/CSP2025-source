#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int N=100000,K=3;
int a[N][K],c[K],p[N],b[N];
int read()
{
	char x;
	int i;
	do x=getchar();
	while (x<'0'||x>'9');
	for (i=0;x>='0'&&x<='9';x=getchar()) i=i*10+x-'0';
	return i;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n,i,j,ans,x,m;
	for (T=read();T;T--)
	{
		n=read();
		for (i=0;i<n;i++) for (j=0;j<K;j++) a[i][j]=read();
		ans=0;
		for (i=0;i<K;i++) c[i]=0;
		for (i=0;i<n;i++)
		{
			p[i]=0;
			for (j=1;j<K;j++) if (a[i][j]>a[i][p[i]]) p[i]=j;
			ans+=a[i][p[i]];
			c[p[i]]++;
		}
		for (i=0;i<K;i++) if (c[i]>n/2) break;
		if (i<K)
		{
			x=i;
			if (x) for (i=0;i<n;i++) swap(a[i][0],a[i][x]);
			m=0;
			for (i=0;i<n;i++) if (p[i]==x) b[m++]=max(a[i][1],a[i][2])-a[i][0];
			sort(b,b+m);
			for (i=n/2;i<m;i++) ans+=b[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
