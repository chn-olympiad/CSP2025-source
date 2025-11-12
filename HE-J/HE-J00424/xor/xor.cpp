#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+100;
ll a[N],n,k,s=0,q=0;
bool f=0;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
		if(a[i]!=a[i-1]&&i!=1) f=1;
	}
	for(int i=1;i<=n;i++){
		s=s^a[i];
		if(s==k){
			s=0;
			q++;
		}
	}
	printf("%lld",q);
	return 0;
}
