#include<iostream>
#include<algorithm>
using namespace std;
struct x{
	long long l,r;
};
long long n,k,m,ans,r;
long long a[50005];
x lr[50005];
long long w(long long l,long long r){
	if (l==r)
		return a[l];
	long long ans=a[l]^a[l+1];
	for (long long i=l+2;i<=r;i++)
		ans^=a[i];
	return ans;
}
bool cmp(x a,x b){
	if (a.r==b.r)
		return a.l<b.l;
	else
		return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for (long long i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for (long long i=1;i<=n;i++)
		for (long long j=1;j<=i;j++)
			if (w(j,i)==k){
				x q;
				q.l=j,q.r=i;
				lr[++m]=q;
			}
	sort(lr+1,lr+m+1,cmp);
	r=lr[1].r;
	ans=1;
	for (long long i=2;i<=m;i++)
		if (lr[i].l>r){
			ans++;
			r=lr[i].r;
		}
	printf("%lld",ans);
	return 0;
}
