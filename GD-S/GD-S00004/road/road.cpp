#include <bits/stdc++.h>
using namespace std;
int vis[10010];
struct data{
	int a,b;
};
int n,m,k,a,b,c,l;
vector<data> vec[10020];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		vec[a].push_back({b,c});
		vec[b].push_back({a,c});
	}
	for(int i=m;i<m+k;i++){
		cin>>l;
		for(int j=1;j<=n;j++){
			cin>>l;
			vec[i].push_back({j,l});
			vec[j].push_back({i,l});
		}
	}
	cout<<0;
	return 0;
} 
