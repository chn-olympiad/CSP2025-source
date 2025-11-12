#include <iostream>
#include <cstdio>
using namespace std;
using LL=long long;
const LL N=5*1e5+5;
LL n,k,a[N],sum[N],maxn;
void try1(){
	LL l=1;
	for(LL r=1;r<=n;r++){
		LL s=sum[r]^sum[l-1];
		while(l<r&&s==k){
			l++;
			s=sum[r]^sum[l-1];
			
		}
		if(r-l>maxn) maxn=r-l;
	}
	cout<<maxn;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(LL i=1;i<=n;i++) cin>>a[i];
	for(LL i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
	try1();
	return 0;
}
