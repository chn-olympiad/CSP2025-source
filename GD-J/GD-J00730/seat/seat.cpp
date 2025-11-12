#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e3 + 10;
int n,m,chk,a_i,r;
int a[N * N];
int mp[N][N];
bool cmp(int a1,int a2){
	return a1 > a2;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	r = a[1];
	stable_sort(a + 1,a + 1 + n * m,cmp);
	chk = 1;
	for (int i = 1;i <= m;i++){
		if (chk){
			for (int j = 1;j <= n;j++){
				mp[j][i] = a[++a_i];
			}
		}
		else{
			for (int j = n;j >= 1;j--){
				mp[j][i] = a[++a_i];
			}
		}
		chk = !chk;
	}
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= m;j++){
//			cout << i << ' ' << j << ' ' << mp[i][j] << "   ";
			if (mp[i][j] == r){
				cout << j << ' ' << i;
				return 0;
			}
		}
//		cout << '\n';
	}
	return 0;
}
