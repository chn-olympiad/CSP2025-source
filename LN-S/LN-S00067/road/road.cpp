#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	int n,m,k,a,b,c[100005],e,f,g,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c[i];
	}
	for(int i=1;i<=k;i++){
		cin>>a>>b>>e>>f>>g;
	}
	for(int i=1;i<=m;i++){
		ans+=c[i];
}
cout<<ans;
}
