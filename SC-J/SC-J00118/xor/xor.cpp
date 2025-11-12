#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#define int long long
using namespace std;
struct work{
	int l,r;
}w[1000005];
int n, k;
int t[1005];
int a[1005];
int y[1005][1005];
int num;
int ans;
bool cmp(work x, work y) {
	if(x.r == y.r) return x.l > y.l;
	return x.r < y.r; 
}
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			y[i][j] = -1;
		}
	}
	for(int i = 1; i <= n; ++i) {
		y[i][i] = a[i];
		if(y[i][i] == k) {
			w[++num].l = i;
			w[num].r = i;
		}
		for(int j = i + 1; j <= n; ++j) {
			y[i][j] = y[i][j - 1] ^ a[j];
			if(y[i][j] == k) {
				w[++num].l = i;
				w[num].r = j;
			}
		}
	}
	sort(w + 1, w + num + 1, cmp);
	for(int i = 1; i <= num; ++i) {
		int flag = 0;
		for(int j = w[i].l; j <= w[i].r; ++j) {
			if(t[j] == 1) {
				flag = 1;
				break;
			}
			t[j] = 1;
		}
		if(!flag) ans++;
	}
	cout << ans << endl;
	return 0;
} 