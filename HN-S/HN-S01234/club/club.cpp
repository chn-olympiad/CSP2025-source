#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXX = 1e5 + 5;

struct pp{
	int x, y, z;
} a[MAXX];

int n, t, vis[MAXX], suma, sumb, sumc, ans;
vector<pair<int, int> > A, B, C;

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.second > b.second;
}

void init(){
	for(int i = 1; i <= n; i++) vis[i] = 0;
	A.clear(), B.clear(), C.clear(), ans = 0;
	suma = sumb = sumc = 0;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n;
		init();
		for(int i = 1; i <= n; i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			int maxx = max(a[i].x, max(a[i].y, a[i].z));
			if(a[i].x == maxx){
				ans += a[i].x;
				suma++, A.push_back({i, a[i].y - a[i].x});
				A.push_back({i, a[i].z - a[i].x});
			}else if(a[i].y == maxx){
				ans += a[i].y;
				sumb++, B.push_back({i, a[i].x - a[i].y});
				B.push_back({i, a[i].z - a[i].y});
			}else{
				ans += a[i].z;
				sumc++, C.push_back({i, a[i].y - a[i].z});
				C.push_back({i, a[i].x - a[i].z});
			}
		}
		sort(A.begin(), A.end(), cmp);
		sort(B.begin(), B.end(), cmp);
		sort(C.begin(), C.end(), cmp);
		//cout << ans << '\n';
		int maxx = max(suma, max(sumb, sumc));
		if(maxx > n / 2){
			if(maxx == suma){
				for(int i = 0; i < A.size() && suma > n / 2; i++){
					if(vis[A[i].first]) continue;
					vis[A[i].first] = 1;
					ans += A[i].second;
					suma--;
				}
			}else if(maxx == sumb){
				for(int i = 0; i < B.size() && sumb > n / 2; i++){
					if(vis[B[i].first]) continue;
					vis[B[i].first] = 1;
					ans += B[i].second;
					sumb--;
				}
			}else{
				for(int i = 0; i < C.size() && sumc > n / 2; i++){
					if(vis[C[i].first]) continue;
					vis[C[i].first] = 1;
					ans += C[i].second;
					sumc--;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
//啦啦啦啦啦，我们一起打睿融 
