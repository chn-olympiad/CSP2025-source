#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e5 + 10;

struct node{
	int a[3];
}a[N];

struct node2{
	int x, id, t;
};

bool operator < (const node2 &a, const node2 &b){
	return a.x > b.x;
}

int T, n, k, b[N];

bool cmp(const node &a, const node &b){
	return a.a[k] > b.a[k];
}

void solve(){
	cin >> n;
	int ans = 0;
	vector<int> v[3];
	for(int i = 1; i <= n; i++){
		int mx = 0;
		for(int j = 0; j < 3; j++){
			cin >> a[i].a[j];
			if(a[i].a[j] > mx){
				mx = a[i].a[j], b[i] = j;
			}
		}
		ans += a[i].a[b[i]];
		v[b[i]].push_back(i);
	}
	int id = -1;
	for(int i = 0; i < 3; i++){
		if(v[i].size() > n / 2){
			id = i;
			break;
		}
	}
	if(id == -1){
		cout << ans << '\n';
		return ;
	}
	vector<int> op;
	for(int p = 0; p < v[id].size(); p++){
		int i = v[id][p], mx = 0;
		for(int j = 0; j < 3; j++){
			if(id != j){
				mx = max(mx, a[i].a[j]);
			}
		}
		op.push_back(a[i].a[id] - mx);
	}
	sort(op.begin(), op.end());
	for(int i = 0; i < op.size() - n / 2; i++){
		ans -= op[i];
	}
	cout << ans << '\n';
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}

