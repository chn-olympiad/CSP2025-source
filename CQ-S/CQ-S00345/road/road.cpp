#include<bits/stdc++.h>
using namespace std;

int k;
long long ans;
long long anssna;
long long n, m;

struct ssss{
	long long x;
	long long y;
	
	long long flag;	
};
ssss x, y, z;
vector<ssss>a[10015];

long long cmp(ssss a, ssss b){
	return a.y < b.y;
}

long long c[15];
long long d[15];
bool vis[15];

struct ztl{
	long long x;
	long long cnt;
	long long las;
	
	bool operator<(const ztl&other)const{
		return cnt > other.cnt;
	}
	
};
ztl xx, yy;

long long sasa(long long ccnt){
	priority_queue<ztl>q;
	xx.x = 1;
	xx.cnt = 0;
	xx.las = 0;
	q.push(xx);
	
	long long cc[n + k + 5];
	for(long long i = 1; i <= n + k; i++){
		cc[i] = 1e18;
	}
	cc[1] = 0;
	long long anssna = 0;
	
	while(!q.empty()){
		xx = q.top();
		q.pop();
		
		if(xx.cnt != cc[xx.x])continue;
		else anssna += xx.las;
		
		for(auto vv : a[xx.x]){
			if(vis[vv.flag]){
				if(xx.cnt + vv.y >= cc[vv.x]){
					continue;
				}
				
				cc[vv.x] = xx.cnt + vv.y;
				yy.x = vv.x;
				yy.cnt = xx.cnt + vv.y;
				yy.las = vv.y;
				q.push(yy);
				
			}
		}
	}
	
	return anssna + ccnt;
}


void aaaa(long long x, long long cnt){
	if(x > k){
		long long cm = sasa(cnt);
		ans = min(ans, cm);
		return;
	}
	vis[x] = 1;
	aaaa(x + 1, cnt + c[x]);
	vis[x] = 0;
	aaaa(x + 1, cnt);
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m;
	cin >> k;
	vis[0] = 1;
	
	for(long long i = 1; i <= m; i++){
		long long u, v, w;
		cin >> u >> v >> w;
		
		x.x = v;
		x.y = w;
		x.flag = 0;
		a[u].push_back(x);
		
		x.x = u;
		x.y = w;
		x.flag = 0;
		a[v].push_back(x);
		
	}
	
	for(long long i = 1; i <= k; i++){
		cin >> c[i];
		for(long long j = 1; j <= n; j++){
			long long cnt;
			cin >> cnt;
			
			x.x = i + n;
			x.y = cnt;
			x.flag = i;
			a[j].push_back(x);
			
			x.x = j;
			x.y = cnt;
			x.flag = i;
			a[i + n].push_back(x);
			
		}
	}
	
	ans = LONG_LONG_MAX;
	aaaa(1, 0);
	
	cout << ans;
	
	return 0;
}
/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
