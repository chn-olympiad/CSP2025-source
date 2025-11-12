#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int N = 1e5+5;
int t, n, a[N][3];
struct node{
	int id, i;
	node(){ id = i = 0; } 
	node(int _id, int _i){ id = _id, i = _i; }
	int val(){
		if(id == 0) return -min(a[i][0]-a[i][1], a[i][0]-a[i][2]);
		else if(id == 1) return -min(a[i][1]-a[i][0], a[i][1]-a[i][2]);
		else return -min(a[i][2]-a[i][0], a[i][2]-a[i][1]);
	}
	
};
bool operator<(node a, node b){
	return a.val() < b.val();
}
int nowid[N];
priority_queue<node, vector<node>, less<node> > q[3];
node getx(int x){
	while(q[x].top().id != nowid[q[x].top().i]) q[x].pop();
	return q[x].top();
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while(t--){
		while(q[0].size()) q[0].pop();
		while(q[1].size()) q[1].pop();
		while(q[2].size()) q[2].pop();
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
		int cnt[3]; memset(cnt, 0, sizeof cnt);
		int rs = 0;
		for(int i = 1; i <= n; i++){
			int va = a[i][0], vb = a[i][1], vc = a[i][2];
			node x;
			if(cnt[0] == n/2){
				
				x = getx(0);
				va += x.val();
//				int j = x.i;
//				if(a[j][1]-a[j][0] >= a[j][2]-a[j][0]) nowid[j] = 1;
//				else nowid[j] = 2;
//				cnt[nowid[j]]++;
//				q.push({nowid[j], j});
			}
			if(cnt[1] == n/2){
				x = getx(1);
				vb += x.val();
//				int j = x.i;
//				if(a[j][2]-a[j][1] >= a[j][0]-a[j][1]) nowid[j] = 2;
//				else nowid[j] = 0;
//				q.push({nowid[j], j});
			}
			if(cnt[2] == n/2){
				x = getx(2);
				vc += x.val();
//				int j = x.i;
//				if(a[j][1]-a[j][0] >= a[j][2]-a[j][0]) nowid[j] = 1;
//				else nowid[j] = 2;
//				q.push({nowid[j], j});
			}
			if(va == max({va, vb, vc})){
				if(x.i && x.id == 0){
					int j = x.i;
					if(a[j][1]-a[j][0] >= a[j][2]-a[j][0]) nowid[j] = 1;
					else nowid[j] = 2;
					cnt[nowid[j]]++;
					q[nowid[j]].push(node{nowid[j], j});
				}
				rs += va;
				q[0].push(node{0, i});
				nowid[i] = 0;
			} else if(vb == max({va, vb, vc})){
				if(x.i && x.id == 1){
					int j = x.i;
					if(a[j][2]-a[j][1] >= a[j][0]-a[j][1]) nowid[j] = 2;
					else nowid[j] = 0;
					cnt[nowid[j]]++;
					q[nowid[j]].push(node{nowid[j], j});
				} 
				rs += vb;
				q[1].push(node{1, i});
				nowid[i] = 1;
			} else if(vc == max({va, vb, vc})){
				if(x.i && x.id == 2){
					int j = x.i;
					if(a[j][1]-a[j][2] >= a[j][0]-a[j][2]) nowid[j] = 1;
					else nowid[j] = 0;
					cnt[nowid[j]]++;
					q[nowid[j]].push(node{nowid[j], j});
				} 
				rs += vc;
				q[2].push(node{2, i});
				nowid[i] = 2;
			}
			if(cnt[nowid[i]] < n/2) cnt[nowid[i]]++;
		}	
		cout << rs << '\n'; 
	}
	return 0;
} 
/*
2020 14533 |18961|
2423 |15344| 16322
1910 6224 |16178|
2038 9963 |19722|
8375 |10557| 5444
3518 |14615| 17976
6188 13424 |16615|
|8769| 509 4394
958 3195 9953
16441 5313 10926

*/
