#include<bits/stdc++.h>
using namespace std;
struct myd{
	long long sz,bm;
};
struct xcy{
	myd a[3];
}a[100010];
bool cmp(myd x,myd y){
	if(x.sz>y.sz){
		return 1;
	}
	if(x.sz<y.sz){
		return 0;
	}
	if(x.bm<y.bm){
		return 1;
	}
	return 0;
}
bool cmp2(xcy x,xcy y){
	if(x.a[0].sz-x.a[1].sz<y.a[0].sz-y.a[1].sz){
		return 1;
	}
	return 0;
}
xcy c[3][100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin >> t;
	while(t--){
		long long n,b[3]={0},ans=0;
		cin >> n;
		for(long long i=0;i<n;i++){
			for(long long j=0;j<3;j++){
				cin >> a[i].a[j].sz;
				a[i].a[j].bm = j;
			}
			sort(a[i].a,a[i].a+3,cmp);
		}
		for(long long i=0;i<n;i++){
			long long bm=a[i].a[0].bm;
			c[bm][b[bm]] = a[i];
			b[bm]++;
			ans += a[i].a[0].sz;
		}
		long long cybm=-1;
		for(long long i=0;i<3;i++){
			if(b[i]>n/2){
				cybm = i;
			}
		}
		if(cybm!=-1){
			sort(c[cybm],c[cybm]+b[cybm],cmp2);
			long long dq=0;
			while(b[cybm]>n/2){
				ans -= c[cybm][dq].a[0].sz-c[cybm][dq].a[1].sz;
				b[cybm]--;
				dq++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
