#include<bits/stdc++.h>
#define int long long
#define N 100010
using namespace std;
int t,n;
struct node{
	int a1,a2,a3;
	int mx,md,id;
}d[N];
bool cmp(node x,node y){
	return x.md>y.md;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(int i=1;i<=n;++i){
			scanf("%lld%lld%lld",&d[i].a1,&d[i].a2,&d[i].a3);
			d[i].mx=max(d[i].a1,max(d[i].a2,d[i].a3));
			if(d[i].a1==d[i].mx)d[i].id=1;
			else if(d[i].a2==d[i].mx)d[i].id=2;
			else d[i].id=3;
			int mn=min(d[i].a1,min(d[i].a2,d[i].a3));
			d[i].md=d[i].mx-(d[i].a1+d[i].a2+d[i].a3-d[i].mx-mn);
		}
		int ans=0,rec=0,p=n/2,sl[4]={0,0,0,0};
		sort(d+1,d+n+1,cmp);
		for(int i=1;i<=n;++i){
			if(sl[d[i].id]<p){
				ans+=d[i].mx;
				++sl[d[i].id];
			}
			else{
				ans+=d[i].mx-d[i].md;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}