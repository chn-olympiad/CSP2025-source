#include<bits/stdc++.h>
#define int long long
const int INF=8.3E18, MAXN=5E5+5;
using namespace std;
inline void io(string name=""){
	if(name.size()){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
}
int n, k, a[MAXN], ps[MAXN], x, y, cnt;
vector<pair<int, int> > ans;
signed main(){
	io("xor");
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		ps[i]=ps[i-1]^a[i];
	}
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
			if((ps[j]^ps[i-1])==k)
				ans.emplace_back(i, j);
	for(auto p:ans){
		if(p.second<=x||(x>=p.first&&y<=p.second)||(p.first>=x&&p.second<=y))
			continue;
		x=p.first;
		y=p.second;
		++cnt;
	}
	cout<<cnt;
	return 0;
}
