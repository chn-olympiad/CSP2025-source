#include<bits/stdc++.h>
#define ll long long
#define inf INT_MAX
#define linf LLONG_MAX
using namespace std;
ll t, n, cnt[3], ans;
bool check(ll i, ll j, ll k){
	return i >= j && j >= k;
}
struct student{
	ll x, y, z, type;
}a[200000];
struct plan{
	ll stuid, from, to, cost;
};
bool cmp(plan A, plan B){
	return A.cost < B.cost;
}
vector<plan> pcl;
bool vis[200000];
void reset(ll i){
	if(check(a[i].x, a[i].y, a[i].z)){
		cnt[0]++;
		a[i].type = 0;
		ans += a[i].x;
	}
	else if(check(a[i].x, a[i].z, a[i].y)){
		cnt[0]++;
		a[i].type = 0;
		ans += a[i].x;
	}
	else if(check(a[i].y, a[i].x, a[i].z)){
		cnt[1]++;
		a[i].type = 1;
		ans += a[i].y;
	}
	else if(check(a[i].y, a[i].z, a[i].x)){
		cnt[1]++;
		a[i].type = 1;
		ans += a[i].y;
	}
	else if(check(a[i].z, a[i].x, a[i].y)){
		cnt[2]++;
		a[i].type = 2;
		ans += a[i].z;
	}
	else if(check(a[i].z, a[i].y, a[i].x)){
		cnt[2]++;
		a[i].type = 2;
		ans += a[i].z;
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		
		cin >> n;
		
		pcl.clear();
		fill(vis, vis + n, false);
		fill(cnt, cnt + 3, 0);
		ans = 0;
		
		for(int i = 0; i < n; i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			reset(i);
		}
//cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << endl;
		if(cnt[0] > n / 2.0){
			for(int i = 0; i < n; i++){
				if(a[i].type == 0){
					pcl.push_back({i, 0, 1, a[i].x - a[i].y});
					pcl.push_back({i, 0, 2, a[i].x - a[i].z});
				}
			}
			
			sort(pcl.begin(), pcl.end(), cmp);
			ll len = pcl.size();
			
			for(int i = 0; i < len; i++){
				if(cnt[pcl[i].to] + 1 <= n / 2.0 && !vis[pcl[i].stuid]){
					vis[pcl[i].stuid] = true;
					cnt[pcl[i].to]++;
					cnt[pcl[i].from]--;
					ans -= pcl[i].cost;
				}
				if(cnt[pcl[i].from] <= n / 2.0){
					break;
				}
			}
		}
		if(cnt[1] > n / 2.0){
			for(int i = 0; i < n; i++){
				if(a[i].type == 1){
					pcl.push_back({i, 1, 0, a[i].y - a[i].x});
					pcl.push_back({i, 1, 2, a[i].y - a[i].z});
				}
			}
			
			sort(pcl.begin(), pcl.end(), cmp);
			ll len = pcl.size();
			
			for(int i = 0; i < len; i++){
				if(cnt[pcl[i].to] + 1 <= n / 2.0 && !vis[pcl[i].stuid]){
					vis[pcl[i].stuid] = true;
					cnt[pcl[i].to]++;
					cnt[pcl[i].from]--;
					ans -= pcl[i].cost;
				}
				if(cnt[pcl[i].from] <= n / 2.0){
					break;
				}
			}
		}
		if(cnt[2] > n / 2.0){
			for(int i = 0; i < n; i++){
				if(a[i].type == 2){
					pcl.push_back({i, 2, 1, a[i].z - a[i].y});
					pcl.push_back({i, 2, 0, a[i].z - a[i].x});
				}
			}
			
			sort(pcl.begin(), pcl.end(), cmp);
			ll len = pcl.size();
			
			for(int i = 0; i < len; i++){
				if(cnt[pcl[i].to] + 1 <= n / 2.0 && !vis[pcl[i].stuid]){
					vis[pcl[i].stuid] = true;
					cnt[pcl[i].to]++;
					cnt[pcl[i].from]--;
					ans -= pcl[i].cost;
				}
				if(cnt[pcl[i].from] <= n / 2.0){
					break;
				}
			}
		}
		
//ll len = pcl.size();
//			
//for(int i = 0; i < len; i++){
//	cout << pcl[i].stuid << " " << pcl[i].from << " " << pcl[i].to << " " << pcl[i].cost << endl;
//}
		cout << ans << endl;
	}
	
	return (0 - 0);
}
