#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int t,n,ans,cnt[5];
struct node{
	int k1,id1,k2,id2;
}d[N];
bool cmp(node x,node y){
	return x.k1-x.k2>y.k1-y.k2;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf ("%lld",&t);
	while (t--){
		scanf ("%lld",&n);
		ans=0;
		for (int i=1;i<=3;i++)
			cnt[i]=0;
		for (int i=1;i<=n;i++){
			int a,b,c;
			scanf ("%lld%lld%lld",&a,&b,&c);
			if (max({a,b,c})==a){
				d[i].k1=a,d[i].id1=1;
				if (max({b,c})==b) d[i].k2=b,d[i].id2=2;
				else d[i].k2=c,d[i].id2=3;
			}
			else
			if (max({a,b,c})==b){
				d[i].k1=b,d[i].id1=2;
				if (max({a,c})==a) d[i].k2=a,d[i].id2=1;
				else d[i].k2=c,d[i].id2=3;
			}
			else{
				d[i].k1=c,d[i].id1=3;
				if (max({a,b})==b) d[i].k2=b,d[i].id2=2;
				else d[i].k2=a,d[i].id2=1;
			}
		}
		sort (d+1,d+n+1,cmp);
		for (int i=1;i<=n;i++)
			if (cnt[d[i].id1]<n/2){
				cnt[d[i].id1]++;
				ans+=d[i].k1;
			}
			else{
				cnt[d[i].id2]++;
				ans+=d[i].k2;
			}
		printf ("%lld\n",ans);
	}
	return 0;
} 
