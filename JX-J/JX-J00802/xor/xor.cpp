#include <bits/stdc++.h>
using namespace std;
long long n,k;
int t=0,ans=0;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		if(a[i]==k) ans++;
		if(a[i]!=a[i+1] && a[i]!=k && a[i+1]!=k) t++;
		if(t==k && k!=0) ans++;
	}
	printf("%d",ans);
	return 0;
}
