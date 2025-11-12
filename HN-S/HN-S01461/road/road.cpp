#include<bits/stdc++.h>
using namespace std;
int n,m,ans,k,a,b,c;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		ans+=c;
	}
	cout<<ans;
	return 0;
} 
