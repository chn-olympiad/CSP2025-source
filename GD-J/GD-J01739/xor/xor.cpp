//T3 xor
//洛谷Bing_laoqi114实名水T3
//根据氷_崎第一定律本题选C 
/*
@ Bing_laoqi114距离CSP只剩 -2小时了你还在这里水
如此状态，如何CSP 
@f_XY 
我要吃麦当劳！
我要吃麦当劳！！
我要吃麦当劳！！！
如此状态，如何CSP 
如此状态，如何CSP

“无耻！ 无耻啊！你站出来！是好汉的站出来！ 
//论杜甫晚年大骂特务 

"汉堡是非常伟大的食物，这是无容质疑的我要吃麦当劳！
"我认为，汉堡不能因为不能放在火锅里我要吃麦当劳！， 就失去它的价值。
"或者说，汉堡会不会放在火锅里也很好吃呢？ "
我要吃麦当劳！
*/
#include <bits/stdc++.h>
//但是我真的很饿。
//本题预计得分10 
using namespace std;
long long n, a[1234567], m, cnt1, cnt2, b[1234567], w, k;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	m = k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	w = b[n];
	if(!b[n] && !k) {
		cout << n;
		return 0;
	}
	if(b[1] == 1 && b[n] == 1) {
		if(k == 1)cout << n;
		if(k == 0)cout << n / 2;
		return 0;
	}
	while(m /= 2)cnt1++;
	while(w /= 2)cnt2++;
	if(cnt2 < cnt1) {
		cout << 0;
		return 0;
	}
	return 0;
}
//我要吃麦当劳！
