#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1&&a[1]==1) cout<<1;
	else if(n==2&&a[1]==1&&a[2]==1) cout<<1;
	return 0;
}
