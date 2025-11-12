#include<bits/stdc++.h>
using namespace std;
const long long MAXN=5e5+5;
long long n,k,a[MAXN],ans,b[MAXN];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i]);
		if(a[i]==1){
			ans++;
		}
	}
	if(k==0){
		cout<<0;
		return 0;
	}else if(k==1){
		cout<<ans;
		return 0;
	}
	return 0;
}
