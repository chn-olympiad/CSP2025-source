#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;

const int maxn = 1e5 + 10;
ll a[maxn][3];
int num[3];
ll ans;
ll df(int p){
	if(p > n)return 0;
	ll ans1 = ans, ans2 = ans, ans3 = ans;
	if(num[0] < n / 2){
		ans1 += a[p][0];
		num[0]++; 
		ans1 += df(p + 1);
		num[0]--;
	}
	if(num[1] < n / 2){
		ans2 += a[p][1];
		num[1]++;
		ans2 += df(p + 1);
		num[1]--;
	}
	if(num[2] < n / 2){
		ans3 += a[p][2];
		num[2]++;
		ans3 += df(p + 1);
		num[2]--;
	}
	return max(ans1, max(ans2, ans3));
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < 3; j++){
				cin >> a[i][j];
			}
		}
		ans = 0;
		num[0] = num[1] = num[2] = 0;
		cout << df(1) << endl;
	}
	return 0;
}
