#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
// k <= 2e6, 20位 
// n <= 5e5
/*
性质1: 若a^b = c , 则 a^c=b,b^c=a 
性质2：令xi = x1 ^ x2 ^ .... xi;
       那么 xi ^ xj = x(i~j) ^
       类似前缀和 -> 前缀异或 
*/
const int N = 5e5 + 50;
int n, k, a[N], x[N], Num = 0;
// 找到所有 符合 条件的 区间后，尾巴小的排在前面，判断 head[i+1] > tail[i] ? ans++ : ans += 0;
struct Node {
	int head, tail;
	bool operator<(const Node A)const{
		if (tail != A.tail) return tail < A.tail;
		return head < A.head;
	}
}ans[N << 1];
int cnt = 0;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		x[i] = x[i - 1] ^ a[i];
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int tmp = x[j] ^ x[i - 1];
			if (tmp == k) {
				cnt++;
				ans[cnt].head = i, ans[cnt].tail = j;
				break;
			}
		}
	}
	
	sort(ans + 1, ans + cnt + 1);
	
	int op = ans[1].tail;
	if (cnt >= 1) Num = 1;
	for (int i = 2; i <= cnt; i++) {
		if (ans[i].head > op) {
			op = ans[i].tail;
			Num++;
		}
	}
	
	cout << Num;
	
	return 0;
}