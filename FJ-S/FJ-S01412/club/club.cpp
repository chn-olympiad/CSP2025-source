#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MAXN 200005
#define MAXA 20005
ll T,n,ans;
ll cnt[4],id[MAXA];
struct L{
	ll a,b,c,w;
};
L A[MAXN];
bool cmp(L x,L y){
	return x.w>y.w;
}
bool pmc(ll x,ll y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>A[i].a>>A[i].b>>A[i].c;
			ll f=max(A[i].a,max(A[i].b,A[i].c));
			ll t=min(A[i].a,min(A[i].b,A[i].c));
			ll s=A[i].a+A[i].b+A[i].c-f-t;
			A[i].w=f-s;
		}
		sort(A+1,A+1+n,cmp);
		for(ll i=1;i<=n;i++){
			ll trk[3]={0};
			id[A[i].a]=1,id[A[i].b]=2,id[A[i].c]=3;
			trk[0]=A[i].a,trk[1]=A[i].b,trk[2]=A[i].c;
			sort(trk,trk+3,pmc);
			if(cnt[id[trk[0]]]<(n/2)){
				ans+=trk[0];
				cnt[id[trk[0]]]++;
			}
			else{
				ans+=trk[1];
				cnt[id[trk[1]]]++;
			}
		}
		cnt[1]=0,cnt[2]=0,cnt[3]=0;
		for(ll i=1;i<=n;i++){
			A[i].w=0;
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
