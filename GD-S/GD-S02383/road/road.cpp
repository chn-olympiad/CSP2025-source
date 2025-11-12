#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c,d,e,f,g[10005][10005],h[10005],hf[10005],q1,sum1,minn[10005],ans; 
vector <int> v[10005];
queue <int> q,sum;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> a >> b >> c;
	for(int i = 1; i <= b; i++){
		cin >> d >> e >> f;
		v[d].push_back(e);
		v[e].push_back(d);
		g[d][e] = g[e][d] = f;
	}
	for(int i = 1; i <= c; i++){
		cin >> d;
		for(int j = 1; j <= a; j++){
			cin >> h[j];
		}
		for(int j = 1; j <= a; j++){
			for(int k = j+1; k <= a; k++){
				if(g[j][k] == 0){
					v[j].push_back(k);
					v[k].push_back(j);
					g[j][k] = g[k][j] = h[j] + h[k];
				}
				g[j][k] = g[k][j] = min(g[j][k],h[j] + h[k]);
			} 
		}
	}
	for(int i = 1; i <= a; i++){
		minn[i] = 1e18;
	}
	minn[1] = 0;
	q.push(1);
	sum.push(0);
	while(!q.empty()){
		q1 = q.front();
		sum1 = sum.front();
		q.pop();
		sum.pop();
		for(int i = 0; i < v[q1].size(); i++){
			if(minn[v[q1][i]] > sum1 + g[v[q1][i]][q1]&& v[q1][i] != 1){
				q.push(v[q1][i]);
				sum.push(sum1 + g[v[q1][i]][q1]);
				minn[v[q1][i]] = sum1 + g[v[q1][i]][q1];
				hf[v[q1][i]] = g[v[q1][i]][q1];
			}
		}
	}
	for(int i = 2; i <= a; i++){
		ans += hf[i];
	}
	cout << ans;
	return 0;
} 
