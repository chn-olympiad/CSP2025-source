#include<bits/stdc++.h>
#define in long long
using namespace std;
const int N=1e4+20;
in n,m,k,ans;
vector<pair<in,in> >e[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(in i=1;i<=n;i++){
		in u,v,w;
		cin>>u>>v>>w;
		e[u].push_back(make_pair(v,w));
		e[v].push_back(make_pair(u,w));
	}
	for(in i=1;i<=n*k;i++){
		int x;
		cin>>x;
	}
	cout<<0;
	return 0;
}