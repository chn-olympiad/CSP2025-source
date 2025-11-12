#include <stdio.h>
#include <string.h>

constexpr int MAXN = 5e5 + 10;

int n, k;
int PreXor[MAXN], arr[MAXN];
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, a, b) for (int i = (a); i <= (b); i++) 

int query(int x, int y) {return PreXor[y] ^ PreXor[x - 1];}
int vis[1 << 22]; // 这个异或值最后出现的位置 

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	scanf("%d %d", &n, &k);
	REP(i, 1, n) scanf("%d", &arr[i]), PreXor[i] = PreXor[i - 1] ^ arr[i]; // 计算异或前缀和 
	
	memset(vis, -1, sizeof(vis));
	
	int LastR = 0, ans = 0; // 最后一个区间的 r 坐标 
	vis[0] = 0;
	REP(i, 1, n) { // 这里枚举 last 
		if (vis[k ^ PreXor[i]] != -1 && LastR < vis[k ^ PreXor[i]] + 1) // 有这个和 
		{
			LastR = i;
			ans++;
		}
		vis[PreXor[i]] = i; // 保存位置 
	}
	printf("%d", ans);
	return 0;
}
