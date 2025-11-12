#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int cnt[15];
int main (){
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0), cout.tie (0);
	string a;
	cin >> a;
	int l = a.size ();
	for (int i = 0; i < l; i ++)
		if (a[i] >= '0' && a[i] <= '9')
			cnt[a[i] - '0'] ++;
	for (int i = 9; i >= 0; i --){
		while (cnt[i]){
			cnt[i] --;
			cout << i;
		}
	}
	return 0;  
} 
