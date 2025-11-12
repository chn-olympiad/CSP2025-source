#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	cout<<time(0)%998244353;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		ans+=w;
	}
	cout<<ans;
	return 0;
}

