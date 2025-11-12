#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll t, n, ans;
ll a[3][100005], c[3];

bool cmp(ll a, ll b){
	return (a > b); 
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int k = 0; k < t; k++){
		cin >> n;
		ans = 0;
		for(int i = 0; i < n; i++){
			for(int l = 0; l < 3; l++){
				cin >> a[l][i];
			}
		}
		for(int l = 0; l < 3; l++){
			sort(a[l], a[l]+n+1, cmp);
		}
		vector <ll> v;
		for(int l = 0; l < 3; l++){
			for(int j = 0; j < n/2; j++){
				v.push_back(a[l][j]);
			}
		}
		sort(v.begin(), v.end(), cmp);
		for(int i = 0; i < n; i++){
			ans += v[i];
		}
		cout << ans << endl;
	}
	return 0;
} 
