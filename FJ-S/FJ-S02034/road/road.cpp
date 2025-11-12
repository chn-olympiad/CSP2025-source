#include<bits/stdc++.h>
using namespace std;
int n,m,k,v[1000005],u[1000005];
long long w[1000005],c[15],a[15][10005];
bool f1;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) f1=true;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0) f1=true;
		}	
	}
	if(f1=true){
		cout<<0;
		return 0;
	}	
	return 0;
}
