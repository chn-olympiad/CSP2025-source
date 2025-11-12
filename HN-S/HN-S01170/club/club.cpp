#include <bits/stdc++.h>
using namespace std;
int t, n, cnt;
struct k{
	int dy,dx,dk,first,second,thirth;
}kl[10005];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t;
		for(int j = 0; j < t; j++){
			cin >> kl[j].first >> kl[j].second >> kl[j].thirth;
		}
	}
	for(int i = 0; i < n; i++){
		cout << kl[t].first / 2;
	}
	return 0;
}
