#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	
	freopen("road.in","r","std.in")
	freopen("road.out","w","std.out")
	int x,n,m,k;
	for(int i=1;i<=n;i++){
		int n,m,k;
		cin>>n>>m>>k;
	}
	for(int i=1;i<=k;i++){
		cin>>x>>n>>m>>k;
	}
	if(n>1) n=1;
	if(k>=10) k=9;
	int sum=n+m+k;
	cout<<sum;
	
	return 0;
}
