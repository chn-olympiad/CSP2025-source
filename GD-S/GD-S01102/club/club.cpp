#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=4e5+5;
ll T,n,a[N][3],cnt[3];
ll ans,m,bz[N],c[N];
struct node{
	ll id,v;
}b[N];
bool cmp(node x,node y){return x.v<y.v;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++)
		for(ll j=0;j<3;j++)
		scanf("%lld",&a[i][j]);
		cnt[0]=cnt[1]=cnt[2]=0;
		for(ll i=1;i<=n;i++)
		bz[i]=0;
		ans=m=0;
		for(ll i=1;i<=n;i++){
			ll t=0;
			for(ll j=0;j<3;j++){
				if(a[i][j]>a[i][t])
				t=j;
			}
			cnt[t]++;
			c[i]=t;
			ans+=a[i][t];
		}
		ll t=0;
		for(int i=0;i<3;i++)
		if(cnt[i]>cnt[t])
		t=i;
		for(int i=1;i<=n;i++){
			if(c[i]!=t)continue;
			for(int j=0;j<3;j++){
				if(t==j)continue;
				b[++m]=(node){i,a[i][t]-a[i][j]};
			}
		}
		sort(b+1,b+m+1,cmp);
		int cur=cnt[t];
		for(ll i=1;i<=n;i++){
			if(bz[b[i].id])continue;
			if(cur<=n/2)break;
			bz[b[i].id]=1;
			ans-=b[i].v;
			cur--;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
