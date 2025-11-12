#include <bits/stdc++.h>
using namespace std;
int n, k, sum[500010], lst[500010];
int las[1 << 21], f[500010];
//lst -> 右端点 i 对应的最大 j
//las -> 当前值为 i 的最大 j
//f -> 上一区间右端点不大于 i 时最大值 
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n && cin >> sum[i]; i ++)//预处理 
		las[sum[i - 1]] = i, lst[i] = las[(sum[i] ^= sum[i - 1]) ^ k];
//	for (int i = 1; i <= n; i ++)cout << lst[i] << " ";
//	cout << '\n';
	for (int i = 1; i <= n; i ++)f[i] = (lst[i] ? max(f[lst[i] - 1] + 1, f[i - 1]) : f[i - 1]);
	cout << f[n];
	return 0;
}
/*
风急天高猿啸哀，渚青沙白鸟飞回。
无边落木萧萧下，不尽长江滚滚来。
万里悲秋常作客，百年多病独登台。
艰难苦恨繁霜鬓，潦倒新停浊酒杯。
*/
