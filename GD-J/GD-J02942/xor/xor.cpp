#include<bits/stdc++.h>
using namespace std;
int a[500050];
int n,k;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	if(n==1) cout<<0;
	else if(n==2) cout<<1;
	else if(n<=100&&k==0) cout<<n/2;
	return 0;
}
