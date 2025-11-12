#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct side{
	int u,v,w;
};

//v,w
vector<side> get_road(int i, vector<side> brd, vector<int> pass){
	vector<side> ans;
	for(auto a : brd){
		if(a.u == i && pass[a.v] == 0){
			ans.push_back(a);
		}
		if(a.v == i && pass[a.u]==0){
			auto t = a;
			t.u = a.v;
			t.v = a.u;
			t.w = a.w;
			int flag = 0;
			for(auto s : ans){
				if(t.u == s.u&&t.v==s.v){
					flag = 1;
					break;
				}
			}
			if(!flag){
				ans.push_back(t);
			}
				
			
			
		}
	}
	return ans;
}

int minn = 1 << 30;
void dfs(vector<int>& pass, vector<side> brd, int now, int val, int depth, const int maxn){
	if(depth == maxn){
		minn = min(minn, val);
		return;
	}
	auto r = get_road(now, brd, pass);

	for(auto i : r){
		auto u = i.u;
		pass[u]=1;
		dfs(pass, brd, i.v, val + i.w, depth + 1, maxn);
		pass[u]=0;
	}
	
}

int main (){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector<side> brd;
	for(int i = 1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		side s = {u,v,w};
		brd.push_back(s);
	}
	vector<int> b(n + 1, 0);
	dfs(b,brd,1,0,1,n);
	cout << minn;
fclose(stdin);
	fclose(stdout);
	return 0;
}
