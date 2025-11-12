#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[100005],v[100005],ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;//城市数量n,道路数量m,改造数量k； 
	for(int i=1;i<=m;i++){
		for(int j=m+1;j<=k;j++){
			cin>>u[i];
			cin>>v[j];
		    ans=min((i+1),(j+m+1));
		}	
	}
	cout<<ans;
	return 0;
}

