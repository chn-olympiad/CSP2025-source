#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int x[N],y[N],z[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	vector<int> a[10010];
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x[i]>>y[i]>>z[i];
		if(y[i]<x[i]) swap(x[i],y[i]);
		a[x[i]].push_back(y[i]);
	}
	int mx=0,c=0;
	for(int i=1;i<=n;i++){
		int o=a[i].size();
		if(mx<o){
			mx=a[i].size();
			c=i;
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		if(y[i]==c||x[i]==c) ans+=z[i];
	}
	if(!k) cout<<ans;
	else cout<<"0";
	return 0;
}
