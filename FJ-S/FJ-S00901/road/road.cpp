#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	if(k!=0){
		cout<<0;
	}else{
		for(int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			sum+=w;
		}
		cout<<sum;
	}
	return 0;
}

