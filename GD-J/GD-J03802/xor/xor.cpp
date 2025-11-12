#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n;
long long k, a[N], pre[N];
struct node{
	int ans, nl, nr;
};
node f(int l, int r){
	if(l == r){
		if(a[l] == k){
//			cout << "l:" << l << " r:" << r << " ans:" << 1 << " nl:" << l << " nr:" << r << endl;
			return {1, l, r};
		}
		else{
//			cout << "l:" << l << " r:" << r << " ans:" << 0 << " nl:" << l + 1 << " nr:" << r - 1 << endl;
			return {0, r + 1, l - 1};
		}
	}
	int mid = (l + r) / 2;
	node ll = f(l, mid), rr = f(mid + 1, r);
	int ans = ll.ans + rr.ans;
	bool flag = 0;
	int ml, mr;
//	cout << l << ' ' << r << ' ' << ll.nr + 1 << ' ' << rr.nl - 1 << endl;
	if(ll.nr + 1 <= rr.nl - 1){
		for(int i = ll.nr + 1; i <= rr.nl - 1; i++){
			for(int j = i + 1; j <= rr.nl - 1; j++){
//				cout << i << ' ' << j << ' ' << (int)(pre[j] ^ pre[i - 1]) << endl;
				if((pre[j] ^ pre[i - 1]) == k){
					flag = 1;
					ml = i, mr = j;
					break;
				}
			}
			if(flag){
				break;
			}
		}
	}
	ans += flag;
	if(ll.ans && rr.ans){
		return {ans, ll.nl, rr.nr};
	}
	if(ll.ans == 0 && rr.ans == 0){
		if(flag){
			return {flag, ml, mr};
		}
		return {0, r + 1, l - 1};
	}
	if(flag){
		if(ll.ans == 0){
			return {ans, ml, max(rr.nl, mr)};
		}
		if(rr.ans == 0){
			return {ans, min(ll.nl, ml), mr};
		}
	}
	else{
		if(ll.ans == 0){
			return {ans, rr.nl, rr.nr};
		}
		if(rr.ans == 0){
			return {ans, ll.nl, ll.nr};
		}
	}
	return {ans, ll.nl, rr.nr};
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		pre[i] = pre[i - 1] ^ a[i];
	}
	cout << f(1, n).ans;
	return 0;
}
