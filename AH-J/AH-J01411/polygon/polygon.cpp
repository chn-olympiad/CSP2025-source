#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
using LL=long long;
const LL N=5e3+5;
const LL INF=99824453;
LL n,a[N],s,sum[N],maxn[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(LL i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(LL i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(LL i=1;i<=n;i++) maxn[i]=max(maxn[i-1],a[i]);
	LL l=1,cnt=0;
	for(LL r=1;r<=n;r++){
		if(sum[r]-sum[l-1]>max(maxn[r],maxn[l-1])) cnt=(cnt+1)%INF;
	}
	cout<<cnt%INF;
	return 0;
}
