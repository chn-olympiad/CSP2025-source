#include<bits/stdc++.h>
using namespace std;
int n, a[5001], d[5001], ans, m;
bool f[5001]{0}, f2[5001]{0};
void d1(int x, int o){
	m = a[x] * 2;
	fill(f + 1, f + 5001, 0);
	fill(f2 + 1, f2 + 5001, 0);
	for(int i = 1, j = 2;i < x || j < x;){
		bool flag = 0;
		if(m < o - d[i] && !f[i]){
			f[i] = 1;
			flag = 1;
			ans++;
			i++;
			d1(x, o - d[i]);
			f[i] = 0;
		}
		if(m < o - a[j] && !f2[j]){
			f2[j] = 1;
			flag = 1;
			ans++;
			j++;
			d1(x, o - a[j]);
			f2[j] = 0;
		}
		if(!flag){
			return;
		}
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		d[i] = d[i - 1] + a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i++){
		if(a[i] * 2 < d[i]){
			ans++;
			d1(i, d[i]);
		}
	}
	cout << ans;
	return 0;
} 