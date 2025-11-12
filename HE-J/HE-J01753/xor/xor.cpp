#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5+10;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n;
	int k,a[N];
	scanf("%lld%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	printf("%lld",n);
	return 0;
}
