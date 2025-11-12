#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T,n,ans;
int cnt[5];
struct ren{
	int a,b,c,fr,se,frid,seid;
}d[N];
bool cmp(ren a,ren b){
	return a.fr-a.se<b.fr-b.se;
}
void tiao(int x){
	sort(d+1,d+1+n,cmp);
	for(int i=1; i<=n; i++){
		if(d[i].frid!=x) continue;
		cnt[x]--,ans-=(d[i].fr-d[i].se);
		if(cnt[x]<=n/2) return;
	}
}
void solve(){
	scanf("%lld",&n);
	ans=0;
	memset(cnt,0,sizeof cnt);
	for(int i=1; i<=n; i++){
		scanf("%lld%lld%lld",&d[i].a,&d[i].b,&d[i].c);
		d[i].fr=d[i].a,d[i].se=-1;
		d[i].frid=1;
		if(d[i].b>d[i].a){
			d[i].se=d[i].a,d[i].seid=1;
			d[i].fr=d[i].b,d[i].frid=2;
		}
		else if(d[i].b>d[i].se){
			d[i].se=d[i].b;
			d[i].seid=2;
		}
		
		if(d[i].c>d[i].fr){
			d[i].se=d[i].fr,d[i].seid=d[i].frid;
			d[i].fr=d[i].c,d[i].frid=3;
		}
		else if(d[i].c>d[i].se){
			d[i].se=d[i].c;
			d[i].seid=3;
		}
		ans+=d[i].fr;
		cnt[d[i].frid]++;
	}
	if(cnt[1]<=n/2 && cnt[2]<=n/2 && cnt[3]<=n/2){
		printf("%lld\n",ans);
		return;
	}
	else{
		if(cnt[1]>n/2) tiao(1);
		if(cnt[2]>n/2) tiao(2);
		if(cnt[3]>n/2) tiao(3);
	}
	printf("%lld\n",ans);
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--) solve();
	return 0;
}
