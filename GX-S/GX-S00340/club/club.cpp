#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
struct node2{
	int val,d;
	bool operator < (const node2& y) const{
		return val>y.val;
	}
};
struct node{
	node2 x[4];
	int maxx;
	bool operator < (const node& y) const{
		return maxx>y.maxx;
	}
}a[N];
int t,n,ans,V[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;++i){
			a[i].maxx=0;
			for(int j=1;j<=3;++j){
				scanf("%lld",&a[i].x[j].val);
				a[i].x[j].d=j;
				a[i].maxx=max(a[i].maxx,a[i].x[j].val);
			}
			sort(a[i].x+1,a[i].x+4);
		}
		sort(a+1,a+n+1);
		fill(V+1,V+4,n>>1);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				if(V[a[i].x[j].d]>0){
					ans+=a[i].x[j].val;
					--V[a[i].x[j].d];
					break;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
