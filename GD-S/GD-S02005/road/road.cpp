#include <bits/stdc++.h>
using namespace std;
#define int long long
int read(){ // ¿ì¶Á 
	int r = 0, w = 1;char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') w = -1;
		ch =getchar();
	} 
	while(isdigit(ch)){
		r = r * 10 + ch - '0';
		ch = getchar();
	}
	return r * w;
}
vector<int> fa(10000 + 5);
struct edge{
	int u, v;
	int flag = -1;
	int w;
	bool operator < (const edge other)const{
		return w < other.w;
	}
	bool operator > (const edge other)const{
		return w > other.w;
	}
};
int find(int x){
	if(fa[x] == x) return x;
	fa[x] = find(fa[x]);
	return fa[x];
}
void add(int u, int v){
	int ufa = find(u);
	fa[ufa] = find(v);
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	
	n = read();m =read();k=read();
	vector<bool> used(k, false);
	vector<vector<int>> a(k, vector<int>(n + 5, 0));
	
	priority_queue<edge, vector<edge>> q;
	for(int i = 1;i <= n;i++) fa[i] = i;
	for(int i = 0;i < m;i++){
		edge tmp;
		tmp.u = read();
		tmp.v = read();
		tmp.w = -read();
		q.push(tmp);
	}
	int maxn = 0;
	for(int i = 0;i < k;i++){
		for(int j = 0;j <= n;j++){
			a[i][j] = read();
			maxn = max(maxn, a[i][j]);
		}
	}
	if(maxn == 0) {
		cout << 0;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			for(int o = 0;o < k;o++){
				edge tmp;
				tmp.u = i;
				tmp.v = j;
				tmp.w = -(a[o][0] + a[o][i] + a[o][j]);
				tmp.flag = o;
				q.push(tmp);
			}
		} 
	}
	int cnt = 0;
	for(int i = 0;i < n - 1;){
		edge cur = q.top();
		int u = cur.u, v = cur.v, w = cur.w;
		q.pop();
		if(find(u) == find(v)) continue;
		i++;
		add(u, v);
		if(cur.flag != -1){
			if(!used[cur.flag]){
				used[cur.flag] = true;
				priority_queue<edge, vector<edge>> tmp;
				while (!q.empty()){
					edge c = q.top();
					q.pop();
					if(c.flag == cur.flag){
						c.w += a[cur.flag][0];
					}
					tmp.push(c);
				}
				q = tmp;
				while (!tmp.empty()){
					tmp.pop();
				}
			}
		}
		cnt -= w;
	}

	cout << cnt;
	return 0;
} 


