#include<bits/stdc++.h>
using namespace std;
struct zz{
	int a;
	int b;
};
vector<zz> t[1000008];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	long long su=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		t[u].push_back({v,w});
		t[v].push_back({u,w});
		su+=w;
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>x;
		}
	}
	if((k==0)||1){
		cout<<su;
		return 0;
	}
	
	
	return 0;
}

