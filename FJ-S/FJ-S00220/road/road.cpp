#include<bits/stdc++.h>

using namespace std;

int n,m,k;
vector<int> g[100100];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int res=0;
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		g[a].push_back(b);
		g[b].push_back(a);
		res+=c;
	}
	for(int i=1;i<=n;i++){
		int c,b;
		res+=c;
		g[i].push_back(b);
		g[b].push_back(a);
	}
	cout<<res;
	return 0;
}

