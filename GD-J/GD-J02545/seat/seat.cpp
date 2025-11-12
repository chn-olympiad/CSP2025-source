#include <bits/stdc++.h>
using namespace std;
const int N = 15*15;
int a[N], n, m, nm, tot=1;
bool cmp(int a, int b){
	return a > b;
} 
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	nm = n*m;
	for (int i = 1; i <= nm; ++i){
		cin >> a[i];
	}
	int r = a[1];
	sort(a+1, a+nm+1, cmp);
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			if (a[tot] == r){
				if (i % 2 ==1){
					cout << i  << " " << j;
					return 0;
				}else{
					cout << i  << " " << (m-j+1);
					return 0;
				}
			}
			tot++;
		}
	}
	return 0;
}
