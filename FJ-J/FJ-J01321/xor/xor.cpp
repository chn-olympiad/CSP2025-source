#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000000],ans,p=1,lx;
long long xr(long long st,long long ed){
	long long anss=a[st];
	for(long long i=st+1;i<=ed;i++)
		anss=(anss|a[i])-(anss&a[i]);
	return anss;
}
struct qj{
	long long l,r;
}s[1000000];
bool bl(qj x,qj y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<n;i++){
		for(int j=i;j<=n;j++){
			if(xr(i,j)==k){
				s[p].l=i,s[p].r=j,p++;
				break;
			}
		}
	}
	sort(s+1,s+p,bl);
	for(int i=1;i<p;i++){
		if(lx<s[i].l)
			lx=s[i].r,ans++;
	}
	printf("%lld",ans);
	return 0;
}
