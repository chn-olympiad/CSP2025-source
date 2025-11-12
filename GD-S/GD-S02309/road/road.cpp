#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node {
	int u,w;
};
vector<node> v[1000009];
vector<int> c[10009];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=m;i++){
		int vg,u,w;
		cin>>vg>>u>>w;
		v[vg].push_back({u,w});
		v[u].push_back({vg,w});
	}
	int mas=0;
	for(int i=1;i<=k;i++){
		int wa;
		cin>>wa;
		mas=max(wa,mas);
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			c[i].push_back(x);		
			mas=max(mas,x);	
		}
	}
	if(!mas){
		
		cout<<0;
		return 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
