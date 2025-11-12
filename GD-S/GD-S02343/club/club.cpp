#include<bits/stdc++.h>
#define PII pair<long long,long long>
using namespace std;
typedef long long ll;
const int N = 1e5 + 100;
struct Node{
	ll idx,w;
	bool operator < (const Node &oji) const{
		return w < oji.w;
	}
	bool operator > (const Node &oji) const{
		return w > oji.w;
	}
};
priority_queue<Node,vector<Node>,greater<Node> >heap[3];
ll a[N][3],ans,n,b[N][3];
void dfs(int k,int c1,int c2,int c3,ll res){
	if(c1 > n / 2 || c2 > n / 2 || c3 > n / 2) return ;
	if(k == n) ans = max(ans,res);
	dfs(k+1,c1+1,c2,c3,res + a[k+1][0]);
	dfs(k+1,c1,c2+1,c3,res + a[k+1][1]);
	dfs(k+1,c1,c2,c3+1,res + a[k+1][2]);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){	
		ans = 0;
		cin >> n;
		int fp = 1;
		for(int i = 1; i <= n; ++i){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			if(a[i][1] && a[i][2]) fp = 0;
			ll u = 0;
			if(a[i][u] < a[i][1]) u = 1;
			if(a[i][u] < a[i][2]) u = 2;
			b[i][0] = u;
			ll v = 0;
			if(u == 0){
				if(a[i][1] > a[i][2]) v = 1;
				else v = 2;
			}else if(u == 1){
				if(a[i][0] > a[i][2]) v = 0;
				else v = 2;
			}else{
				if(a[i][0] > a[i][1]) v = 0;
				else v = 1;
			}
			b[i][1] = v;
		}
		if(fp){
			for(int i = 1; i <= n; ++i){
				ll k = i;
				ll id = b[i][0];
				if(heap[id].size() == n/2){
					Node tmp,obj;
					tmp = heap[id].top();
					ll idx = tmp.idx;
					if(a[idx][b[idx][0]] - a[idx][b[idx][1]] > a[i][id] - a[i][b[i][1]]){
						id = b[i][1];
					}else{
						k = idx;
						heap[id].pop();
						obj.idx = i;
						obj.w = a[i][id];
						heap[id].push(obj);
						id = b[idx][1];
					}
				}
				Node obi;
				obi.idx = k;
				obi.w = a[k][id];
				heap[id].push(obi);		
			}
			for(int i = 0; i <= 2; ++i){
				while(heap[i].size()){
					Node tmp;
					//cout << i << " ";
					tmp = heap[i].top();
					heap[i].pop();
					ans += tmp.w;
				}
			}						
		}else{
			dfs(1,1,0,0,a[1][0]);
			dfs(1,0,1,0,a[1][1]);
			dfs(1,0,0,1,a[1][2]);
		}
		cout << ans << endl;
	}
	return 0;
}
