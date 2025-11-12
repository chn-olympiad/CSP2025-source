#include<bits/stdc++.h>
using namespace std;
using LL = long long;
LL a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	LL n,k;
	cin>>n>>k;
	for(LL i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	if(k==0){
		cout<<1;
		return 0;
	}
	LL cnt1=1;
	for(LL i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			cnt1++;
		}
	}
	if(k==1) cout<<cnt1;
	else cout<<1;
	return 0;
}
