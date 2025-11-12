#include <bits/stdc++.h>
using namespace std;
const int N = 5100,mod = 998244353;
int n,a[N],res;
bool f[30][30][110][110];
void solve1(int x,int cnt,int Max,int Sum)
{
	if(x == n + 1) return ;
	if(cnt >= 3 && Sum > Max * 2)
	{
		bool flag = 0;
		for(int i = 1;i < x;++i) 
		{
			if(f[i][cnt][Max][Sum] != 0)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			++res;
			f[x][cnt][Max][Sum] = 1;
		}
	} 
	solve1(x + 1,cnt + 1,max(Max,a[x + 1]),Sum + a[x + 1]);
	solve1(x + 1,cnt,Max,Sum);
}
void solve()
{
	scanf("%d",&n);
	int cnt = 0;
	for(int i = 1;i <= n;++i) scanf("%d",a + i);
	sort(a + 1,a + 1 + n);
	if(n <= 20)
	{
		solve1(0,0,0,0);
		printf("%d\n",res);
		return ;
	}
	cnt = 0;
	for(int i = n - 2,j = 1,z = 1;i >= 1;--i,j += (n - 3) * z,++z)
	{
		cnt = cnt + ((i * j) % mod);
		cnt %= mod;
	}
	printf("%d\n",cnt);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	solve();
}
/*
123 124 125 126 134 135 136 145 146 156 234 235 236 245 246 256 345 346 356 456
1234 1235 1236 1245 1246 1256 1345 1346 1356 1456 2345 2346 2456 3456 12345 12346 12356 12456 13456 23456
123456

*/
