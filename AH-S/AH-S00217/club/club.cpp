#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{
	long long f1,f2,sum;
}f[100005];
bool cmp(node p1,node p2){
	return p1.sum>p2.sum;
}
long long t,n,x,y,z;
int main(){
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	scanf("%lld",&t);
	while (t--){
		long long ans=0;
		scanf ("%lld",&n);
		memset(f,0,sizeof(f));
		long long cnt[5]={0};
		for (long long i=1;i<=n;i++){
			scanf ("%lld%lld%lld",&x,&y,&z);
			long long mx=max(x,max(y,z));
			long long mn=min(x,min(y,z));
			long long sm=x+y+z-mx-mn;
			ans+=mx;
			f[i].sum=mx-sm;
			if (mx==x)
				f[i].f1=1;
			else if (mx==y)
				f[i].f1=2;
			else
				f[i].f1=3;
		}
		sort (f+1,f+n+1,cmp);
		long long nx=n/2;
		for (long long i=1;i<=n;i++){
			if (cnt[f[i].f1]==nx)
				ans-=f[i].sum;
			else
				cnt[f[i].f1]++;
		}
		printf ("%lld\n",ans);
	}
	return 0;
}
