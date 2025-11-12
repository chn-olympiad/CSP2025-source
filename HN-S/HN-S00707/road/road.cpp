#include <bits/stdc++.h>
using namespace std;
int n,m,k,a,x,zd;
long long s;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>x>>a;
		zd=max(a,zd);
		s+=a;
	}
	for(int i=1;i<=k+n+1;i++){
		cin>>x;
	}
	cout<<s-zd;
	return 0;
} 
