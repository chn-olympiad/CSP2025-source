#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int maxn = 1e5 + 5;

int T, n, ans;
int a[maxn], b[maxn], c[maxn];

void read(int &x){
	x = 0;
	int f = 1;
	char c = getchar();
	while (!isdigit(c)){
		if (c == '-'){
			f = -1;
		}
		c = getchar();
	}	
	while (isdigit(c)){
		x = x * 10 + c - 48;
		c = getchar();
	}
	x *= f;
	return ;
}

void write(int x){
	if (x < 0){
		x = -x;
		putchar('-');
	}	
	if (x >= 10){
		write(x / 10);
	}
	putchar(x % 10 + '0');
	return ;
}

bool cmp(int x, int y){
	return x > y;
}

void dfs(int i, int tot1, int tot2, int tot3, int cnt){
	if (i - 1 == n){
		ans = max(ans, cnt);
		return ;
	}
	if (tot1 > 0){
		dfs(i + 1, tot1 - 1, tot2, tot3, cnt + a[i]);
	}
	if (tot2 > 0){
		dfs(i + 1, tot1, tot2 - 1, tot3, cnt + b[i]);
	}
	if (tot3 > 0){
		dfs(i + 1, tot1, tot2, tot3 - 1, cnt + c[i]);
	}
	return;
} 

void ddfs(int i, int tot1, int tot2, int tot3, int cnt){
	if (i - 1 == n){
		ans = max(ans, cnt);
		return ;
	}
	if (tot1 <= n / 2){
		ddfs(i + 1, tot1 + 1, tot2, tot3, cnt + a[i]);
	}
	if (tot2 <= n / 2){
		ddfs(i + 1, tot1, tot2 + 1, tot3, cnt + b[i]);
	}
	if (tot3 <= n / 2){
		ddfs(i + 1, tot1, tot2, tot3 + 1, cnt + c[i]);
	}
	return;
}

void dfs2(int i, int tot1, int tot2, int cnt){
	if (i - 1 == n){
		ans = max(ans, cnt);
		return ;
	}
	if (tot1 > 0){
		dfs2(i + 1, tot1 - 1, tot2, cnt + a[i]);
	}
	if (tot2 > 0){
		dfs2(i + 1, tot1, tot2 - 1, cnt + b[i]);
	}
	return ;
}

void solve(){
	read(n);
	int flag_a = 1;
	int flag_b = 1;
	for (int i = 1; i <= n; ++i){
		read(a[i]), read(b[i]), read(c[i]);
		if (b[i] != 0 || c[i] != 0){
			flag_a = 0; 
		}
		if (c[i] != 0){
			flag_b = 0;
		}
	} 
	if (flag_a){
		sort(a + 1, a + n + 1, cmp);
		int ans = 0;
		for (int i = 1; i <= n / 2; ++i){
			ans += a[i];
		}
		write(ans);
		putchar('\n');
		return ;
	}
	if (flag_b){
		dfs2(1, n / 2, n / 2, 0);
		write(ans);
		putchar('\n');
		return ;
	}
//	dfs(1, n / 2, n / 2, n / 2, 0);
	ddfs(1, 0, 0, 0, 0);
	write(ans);
	putchar('\n');
	return ;
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	read(T);
	while (T--){
		solve();
		n = ans = 0;
		for (int i = 1; i <= n; ++i){
			a[i] = b[i] = c[i] = 0;
		}
	}
	return 0;
}
/*
思路：
贪心不行，那就搜索吧 
dp想不出来
搜索应该能拿个50吧 
后记：
先想到贪心
先对于三个部门都进行排序，计算每个人可以获得的的最大值
能放大的先放，放完在排序放剩下两个部门
让每一个部门能获得的最大值都最大
或
把每个人三个值的最大的部门拿去分配
让每个人产生的贡献最大
但感觉是dp题
贪心可能是错的 
第二个贪心应该是错的
因为我们无法判断这个社团是否已经满人 
所以抛弃 
第一个贪心也是错的，样例就hack掉了 
废了
/mad 
*/
