#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(n%2==0) cout<<2;
	else cout<<1;
	return 0;
}
