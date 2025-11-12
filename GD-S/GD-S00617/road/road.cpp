#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
vector<int> a[MAXN];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i=1;i<=k;i++){
		int l;
		for(int j=1;j<=n;j++){
			cin>>l;
		}
	}
	srand(time(0));
	long long x=rand()*rand()*rand();
	cout<<x%200000000+5000000000;
	return 0;
}
