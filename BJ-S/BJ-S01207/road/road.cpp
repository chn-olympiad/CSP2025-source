#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[1000005][2][2],t;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i][1][1];
	}
	for(int i=1;i<=k*(n+1);i++){
		cin>>t;
	}
	t=0;
	for(int i=1;i<=n-1;i++){
		t+=a[i][1][1];
	}
	cout<<t;
	return 0;
}
