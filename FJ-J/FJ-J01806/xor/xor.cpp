#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
ll n, k, cnt = 1;
ll ans;
int a[N];
struct lenth{
	int begin, end;
} b[N];
ll erth(int a){
	ll et_a = 0;
	int len = 0;
	stack <int> st;
	while(a != 0){
		st.push(a % 2);
		a /= 2;
		len++;
	}
	for(int i = 1;i <= len;i++){
		et_a *= 10;
		et_a += st.top();
		st.pop();
	}
	return et_a;
}
ll orx(int a, int b){
	if((a == 1 && b == 0) || (b == 0 && a == 1)){
		return 1;
	}
	if(a == b){
		return a;
	}
	ll answer = 0;
	int ae = erth(a), be = erth(b);
	while(ae != 0 || be != 0){
		int a1 = ae % 10;
		int b1 = be % 10;
		ae /= 10;
		be /= 10;
		if(a1 != b1){
			answer *= 10;
			answer += 1;
		}
	}
	return answer;
}
ll fororx(int l, int r){
	if(l == r){
		return erth(a[l]);
	}
	ll sum = 0;
	int b[N] = {0};
	for(int i = l;i <= r;i++){
		sum = orx(sum, a[i]);
	}
	return sum;
}
bool cmp(lenth a, lenth b){
	return a.end < b.end;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(k == 0){
		sort(a + 1, a + n + 1);
		if(a[1] = 1){
			cout << 0;
			return 0;
		}
		int ans_0 = 0;
		for(int i = 1;i <= n;i++){
			if(a[i] == 0){
				ans_0++;
			}
		}
		cout << ans_0;
		return 0;
	}
	sort(a + 1, a + n + 1);
	if(a[1] == 0 && a[n] == 1){
		if(k != 0 && k != 1){
			cout << 0;
			return 0;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			int tot = fororx(i, j);
			if(tot == erth(k)){
				cnt++;
				b[cnt].begin = i;
				b[cnt].end = j;
			}
		}
	}
	sort(b + 1, b + cnt + 1, cmp);
	for(int i = 1;i <= cnt;i++){
		if(b[i].end <= b[i+1].begin){
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
