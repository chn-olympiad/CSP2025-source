#include<cstdio>
using namespace std;
const int MAXN=5000;
const long long mod=998244353;
int n,a[MAXN+10];
int ta[MAXN+10];
void msort(int l,int r) {
	if(l>=r) {
		return;
	}
	int mid=(l+r)>>1;
	msort(l,mid);
	msort(mid+1,r);
	int p1=l,p2=mid+1;
	for(int i=l; i<=r; i++) {
		if((p2>r)||((p1<=mid)&&(a[p1]<a[p2]))) {
			ta[i]=a[p1];
			++p1;
		} else {
			ta[i]=a[p2];
			++p2;
		}
	}
	for(int i=l; i<=r; i++) {
		a[i]=ta[i];
	}
	return;
}
long long f[(MAXN+10)<<1],sumf=0,ans=0;
void upd(int val) {
	ans+=sumf;
	if(ans>=mod) {
		ans-=mod;
	}
	for(int i=val+1; i<=(MAXN<<1); i++) {
		ans+=f[i];
		if(ans>=mod) {
			ans-=mod;
		}
	}
	sumf<<=1;
	if(sumf>=mod) {
		sumf-=mod;
	}
	for(int i=(MAXN<<1)+1; i>=(MAXN<<1)+1-val; i--) {
		sumf+=f[i];
		if(sumf>=mod) {
			sumf-=mod;
		}
	}
	for(int i=(MAXN<<1); i>=val; i--) {
		f[i]+=f[i-val];
		if(f[i]>=mod) {
			f[i]-=mod;
		}
	}
	return;
}
int main(void) {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	msort(1,n);
	f[0]=1;
	for(int i=1; i<=n; i++) {
		int poi=i;
		while(a[poi+1]==a[i]&&poi+1<=n) {
			++poi;
		}
		for(int j=i; j<=poi; j++) {
			upd(a[j]);
		}
		i=poi;
	}
	printf("%lld",ans);
	return 0;
}
