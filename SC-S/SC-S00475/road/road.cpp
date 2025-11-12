#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,v,sx,sy,t;
long long zt,z;
int c[10001];
int a[10001][10001];
int d[10011];
struct el{
	int x;
	int y;
	int v;
	bool operator < (const el &a)const{
		return v < a.v;
	}
};
vector<el> w;
vector<el> wf;
bool f0 = true;
inline int f(int x){
	return (x == d[x]) ? x : d[x] = f(d[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i = -~i){
		cin >> x >> y >> v;
		w.push_back({x,y,v});
	}
	for(int i = 1;i <= k;i = -~i){
		cin >> c[i];
		f0 &= (!c[i]);
		for(int j = 1;j <= n;j = -~j){
			cin >> a[i][j];
		}
	}
	if(f0){
		sort(w.begin(),w.end());
		for(int i = 1;i <= n;i = -~i){
			d[i] = i;
		}
		for(auto e : w){
			sx = f(e.x);
			sy = f(e.y);
			if(sx == sy){
				continue;
			}
			d[sy] = sx;
			zt += e.v;
			t++;
			if(t == (n - 1)){
				break;
			}
		}
		for(int i = 1;i <= k;i = -~i){
			for(int j = 1;j <= n;j = -~j){
				w.push_back({n + i,j,a[i][j]});
			}
		}
		sort(w.begin(),w.end());
		for(int i = 1;i <= (n + k);i = -~i){
			d[i] = i;
		}
		t = 0;
		for(auto e : w){
			sx = f(e.x);
			sy = f(e.y);
			if(sx == sy){
				continue;
			}
			d[sy] = sx;
			z += e.v;
			t++;
			if(t == (n + k - 1)){
				break;
			}
		}
		cout << min(z,zt);
		return 0;
	}
	z = 1e18;
	for(int p = 0;p < (1 << k);p = -~p){
		zt = 0;
		wf = w;
		for(int i = 0;i < k;i = -~i){
			if((p >> i) & 1){
				zt += c[i + 1];
				for(int j = 1;j <= n;j = -~j){
					wf.push_back({n + i + 1,j,a[i + 1][j]});
				}
			}
		}
		if(zt > z){
			continue;
		}
		for(int i = 1;i <= (n + k);i = -~i){
			d[i] = i;
		}
		sort(wf.begin(),wf.end());
		t = 0;
		for(auto e : wf){
			sx = f(e.x);
			sy = f(e.y);
			if(sx == sy){
				continue;
			}
			d[sy] = sx;
			zt += e.v;
			t++;
			if(t == (n + __builtin_popcount(p) - 1)){
				break;
			}
		}
		z = min(z,zt);
	}
	cout << z;
	return 0;
}