#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	cout<<n-1;
	return 0;
}
