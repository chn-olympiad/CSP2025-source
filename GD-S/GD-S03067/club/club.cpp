/*
在远方的荒野里
当人们提起你的名字，都包含敬畏与惋惜之情
没有人能驯服我们野蛮的灵魂，而你接受了挑战
在最苍白的注视下，你教授，我们改变
本能得到了救赎
你给虫子们带来他们意想不到的世界
                        ——《圣巢挽歌》教师莫诺蒙 编写 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=350;
template<typename T>void qr(T& x)
{
	x=0;int f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(; isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
struct node{int x,y,z;}a[N];
int f[N][N][N],n;
inline int dfs(int sa,int sb,int sc,int x)
{
	if(x==n+1)return 0;
	if(f[sa][sb][sc])return f[sa][sb][sc];
	f[sa][sb][sc]=0;
	if(sa<n/2)f[sa][sb][sc]=max(f[sa][sb][sc],dfs(sa+1,sb,sc,x+1)+a[x].x);
	if(sb<n/2)f[sa][sb][sc]=max(f[sa][sb][sc],dfs(sa,sb+1,sc,x+1)+a[x].y);
	if(sc<n/2)f[sa][sb][sc]=max(f[sa][sb][sc],dfs(sa,sb,sc+1,x+1)+a[x].z);
	return f[sa][sb][sc];
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;qr(T);
	while(T--)
	{
		qr(n);
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)qr(a[i].x),qr(a[i].y),qr(a[i].z);
		printf("%lld\n",dfs(0,0,0,1));
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
