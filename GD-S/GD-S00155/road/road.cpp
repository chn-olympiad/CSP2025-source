#include<bits/stdc++.h>
using namespace std;

int n, m, k, ans=1e9;
vector<vector<pair<int, int>>> p(1e5+1);
vector<int> po(1e5+1); 

void go(int n_ans, int t){
	cout<<n_ans<<' '<<t<<endl;
	if(t == n+k-1){
		ans = min(ans, n_ans);
		return;
	}
	for(int i=0;i<p[t].size();i++){
		if(po[p[t][i].first]){
			continue;
		}
		po[p[t][i].first]++;
		go(n_ans + p[t][i].second, t+1);
		po[p[t][i].first]--;
	}
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u, v, w;
		cin>>u>>v>>w;
		p[u].push_back(make_pair(v, w));
		p[v].push_back(make_pair(u, w));
	}
	for(int i=1;i<=k;i++){
		int w, a, b, c, d;
		cin>>w;
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
//			p[j].push_back(make_pair(n+k, w+x));
//			p[n+k].push_back(make_pair(j, w+x));
//			p[j].push_back(make_pair(n+k, 0));
//			p[n+k].push_back(make_pair(j, 0));
		}
	}
	go(0, 1);
	cout<<ans/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
