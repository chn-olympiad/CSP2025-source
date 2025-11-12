#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

long long n, ans;
int a[5001];
void put(int lei, int cen, vector<int> v){
	if (cen == n) return;
	int maxx = -1;
	for (int x : v){
		maxx = max(maxx, x);
	}
	if (cen >= 2){
		for (int i=maxx+1; i<=n; i++){
			if (any_of(v.begin(), v.end(), [&](int x){return x==i;})){
				continue;
			}
			if (lei > a[i]) ans++;
			ans = ans % 998244353;
		}
	}
	for (int i=maxx+1; i<=n; i++){
		if (any_of(v.begin(), v.end(), [&](int x){return x==i;})){
			continue;
		}
		vector<int> tv = v;
		tv.push_back(i);
		put(lei + a[i], cen + 1, tv);
	}
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
	for (int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	
	for (int i=1; i<=n; i++){
		vector<int> tv;
		tv.push_back(i);
		put(a[i], 1, tv);
	}
	cout << ans % 998244353;
    return 0;
}

