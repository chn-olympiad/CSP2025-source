#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[10005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(ll i=0;i<n;i++){
		scanf("%lld",&a[i]);		
	}
	printf("%lld",n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
