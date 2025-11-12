#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int u[1000005],v[1000005],w[1000005];

void pian(){
	
	for (int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	
	sort(w+1,w+n+1);
	
	int ans=0,ma=0;
	
	for(int i=1;i<=n;i++){
		ans+=w[i];
		ma=max(ma,w[i]);
	}
	
	cout<<ans-ma;
	
	
	return ;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	
	if (k==0){
		pian();
		return 0;
	}
	
	
	
	
	return 0;
}
