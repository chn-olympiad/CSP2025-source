#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N][4] , vis[N] , now[N] , f[35];
priority_queue< pair<int , pair<int , int> > > q;
priority_queue< pair<int , int> , vector< pair<int , int> > , greater< pair<int , int> > > pq[4];
int nv , best;
void dfs(int i , int n) {
	if(i > n) {
		best = max(best , nv);
		return;
	}
	for(int j = 1 ; j <= 3 ; j ++) {
		if(now[j] + now[j] >= n) continue;
		now[j] ++;
		nv += a[i][j];
		dfs(i + 1 , n);
		nv -= a[i][j];
		now[j] --;
	}
}
struct node{
	int w , i , j;
	node() {
		
	}
	node(int w , int i , int j) {
		this->w = w , this->i = i , this->j = j;
	}
}b[N];
int tot , pre[N] , mx[N];
bool cmp(node x , node y) {
	return x.w > y.w;
}
void dfs2(int i , int n) {
	if(i > tot || now[1] + now[2] + now[3] == n) {
		best = max(best , nv);
		return;
	}
	int lst = n - (now[1] + now[2] + now[3]);
	if(i + lst > tot || nv + pre[i + lst - 1] - pre[i - 1] <= best) {
		return;
	} 
	if(!f[b[i].i] && now[b[i].j] + now[b[i].j] < n) {
		nv += b[i].w;
		f[b[i].i] = 1;
		now[b[i].j] ++;
	    dfs2(i + 1 , n);
	    now[b[i].j] --;
	    f[b[i].i] = 0;
		nv -= b[i].w;	
	} 
	if(mx[b[i].i] < b[i].w || f[b[i].i]) dfs2(i + 1 , n);
}
int ca[N] , da[N];
void solve() {
	int n;
	long long ans = 0;
	cin >> n;
	if(n <= 30) {
	    tot = 0;
		for(int i = 1 ; i <= n ; i ++) {
			mx[i] = 0x3f3f3f3f;
			int o = 0 , nex = 0;
			for(int j = 1 ; j <= 3 ; j ++) {
				cin >> a[i][j];
				mx[i] = min(mx[i] , a[i][j]);
				if(o < a[i][j]) nex = o , o = a[i][j];
				else if(nex < a[i][j]) nex = a[i][j]; 
				b[++ tot] = node(a[i][j] , i , j);
			}
			ca[i] = o - nex;
			da[i] = mx[i];
		}
		best = 0;
		if(n <= 1) dfs(1 , n);
		else {
		    memset(f , 0 , sizeof(f));
		    sort(b + 1 , b + tot + 1 , cmp);
			for(int i = 1 ; i <= tot ; i ++) pre[i] = pre[i - 1] + b[i].w;
			dfs2(1 , n);
		}
		cout << best << '\n';
		return;
	} 
	memset(vis , 0 , sizeof(vis));
	for(int i = 1 ; i <= n ; i ++) {
		for(int j = 1 ; j <= 3 ; j ++) {
			cin >> a[i][j];
			q.push(make_pair(a[i][j] , make_pair(i , j)));
		}
	}
	for(int i = 1 ; i <= 3 ; i ++) {
		while(!pq[i].empty()) pq[i].pop();
		now[i] = 0;
	}
	while(!q.empty()) {
		int w = q.top().first , i = q.top().second.first , j = q.top().second.second;
		q.pop();
		if(vis[i]) continue;
		if(now[j] + now[j] >= n) {
			int nw = pq[j].top().first , ni = pq[j].top().second;
			int cnt = 0;
			for(int k = 1 ; k <= 3 ; k ++) {
				if(k == j) continue; 
				if(now[k] + now[k] < n && a[ni][k] > a[ni][cnt]) cnt = k;
			}
			if(cnt == 0) continue;
			if(w - nw > 0) {
				pq[j].pop();	
			    pq[j].push(make_pair(ca[i] , i));
			    pq[cnt].push(make_pair(da[ni] , ni));
				ans += w - nw;
				now[cnt] ++;
				vis[i] = 1;
			}
		} else {
			vis[i] = 1;
			now[j] ++;
			ans += w;	
			pq[j].push(make_pair(ca[i] , i));
		}
	}
	cout << ans << '\n';
}
int main() {
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	int t;
	cin >> t;
	while(t --) solve();
	return 0;
}
// csp 2025 rp ++
/*
Ren5Jie4Di4Ling5%
*/
