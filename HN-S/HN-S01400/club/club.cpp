#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cstring>
#include<set>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
int a[N][5];
int cnt[5], dis[N];
void solve(){
	int n;
	cin >> n;
	int sum = 0;
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; i++){
		int maxi = 1;
		for(int j = 1; j <= 3; j++){
			cin >> a[i][j];
			if(a[i][j] > a[i][maxi]){
				maxi = j;
			}
		}
		sum += a[i][maxi];
		cnt[maxi]++;
	}
	auto check = [&](){
		for(int i = 1; i <= 3; i++){
			if(cnt[i] > n / 2){
				return false;
			}
		}	
		return true;
	};
	if(check()){
		cout << sum << "\n";
		return;
	}
	int f = 1;
	for(int i = 1; i <= 3; i++){
		if(cnt[i] > n / 2){
			f = i;
		}
	}
	multiset<int> st;
	for(int i = 1; i <= n; i++){
		int mx = f;
		for(int j = 1; j <= 3; j++){
			if(a[i][j] > a[i][mx]){
				mx = j;
			}
		}
		sort(a[i] + 1, a[i] + 4);
		if(mx == f){
			st.insert(a[i][3] - a[i][2]);
		}
	}
	for(int i = 1; i <= (cnt[f] - n / 2); i++){
		int s = *st.begin();
		sum -= s;
		st.erase(st.begin());
	}
	cout << sum << "\n";
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
