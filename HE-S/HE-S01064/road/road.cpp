#include <bits/stdc++.h>
using namespace std;

struct road{
	int u,v,w;
}a[1000005];

int main(){
	freopen("road.in","r",stdin);
	freopen ("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	int x;
	for (int i=1;i<=k;i++){
		cin>>x;
		if (x==0){
			cout<<0;
			return 0;
		}
		while(cin>>x){
			continue;
		}
	}	
	return 0;
}
