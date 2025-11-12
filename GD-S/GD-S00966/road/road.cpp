#include<bits/stdc++.h>
using namespace std;
int p[11];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a,b,c;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
	}
	for(int j=1;j<=k;j++){
		cin>>p[j];
		int z;
		for(int i=1;i<=n;i++) cin>>z;
	}
	sort(p+1,p+1+k);
	cout<<p[1];
	return 0;
}
