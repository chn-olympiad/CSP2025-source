#include<bits/stdc++.h>
using namespace std;
int n,m,qz[10005],a[10005];
int main(){
	freopen(" xor in", "r",stdin);
	freopen(" xor out", "w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
	qz[i]=a[i]^qz[i-1];
	
}
	return 0;
}
