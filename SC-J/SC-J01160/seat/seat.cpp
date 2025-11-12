#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define ls(u) u << 1
#define rs(u) u << 1 | 1
using namespace std;
const int maxn = 1000 + 55, mod = 998244353;
const double pi = acos(-1);
int T;
int n, m;
int a[maxn];
int w, h, l;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i ++){
		cin >> a[i];
	}
	w = a[1];
	sort(a + 1, a + n * m  + 1);
	h = 1, l = 1;
	for(int i = n * m;i >= 1;i --){
		if(w == a[i]){
			cout << l << " " << h;
			return 0;
		}
		if(h == n && l % 2 == 1){
			l ++;
			continue;
		}else if(h == 1 && l % 2 == 0){
			l ++;
			continue;
		}
		if(l % 2 == 1){
			h ++;
		}else h --;
	}
	return 0;
}