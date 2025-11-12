#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5,INF=1e16;
struct node{
	ll x,y;
	bool operator<(const node &c) const{
		return y<c.y;
	}
};
ll T,n,m;
ll a[N+5][4];
ll d[N+5],cnta,cntb,cntc;
ll ans;
priority_queue<node,vector<node>,less<node> > ab,ba,bc,cb,ac,ca;
void clearr(){
	while(!ab.empty() && d[ab.top().x]!=1) ab.pop();
	while(!ac.empty() && d[ac.top().x]!=1) ac.pop();
	while(!ba.empty() && d[ba.top().x]!=2) ba.pop();
	while(!bc.empty() && d[bc.top().x]!=2) bc.pop();
	while(!ca.empty() && d[ca.top().x]!=3) ca.pop();
	while(!cb.empty() && d[cb.top().x]!=3) cb.pop();
	return;
}
void pusha(ll x){
	ll aa=a[x][1],bb=a[x][2],cc=a[x][3];
	ans+=aa,d[x]=1,cnta++;
	ab.push((node){x,-aa+bb});
	ac.push((node){x,-aa+cc});
	return;
}
void pushb(ll x){
	ll aa=a[x][1],bb=a[x][2],cc=a[x][3];
	ans+=bb,d[x]=2,cntb++;
	ba.push((node){x,-bb+aa});
	bc.push((node){x,-bb+cc});
	return;
}
void pushc(ll x){
	ll aa=a[x][1],bb=a[x][2],cc=a[x][3];
	ans+=cc,d[x]=3,cntc++;
	ca.push((node){x,-cc+aa});
	cb.push((node){x,-cc+bb});
	return;
}
void solve(){
	for(ll i=1;i<=n;i++){
		ll aa=a[i][1],bb=a[i][2],cc=a[i][3];
		if(aa>=bb && aa>=cc){
			if(cnta>=m){
				if(aa==bb) pushb(i);
				else if(aa==cc) pushc(i);
				else{
					clearr();
					node abb,acc;
					if(!ab.empty()) abb=ab.top();
					else abb=(node){0,-INF};
					if(!ac.empty()) acc=ac.top();
					else acc=(node){0,-INF};
					ll tob=-aa+bb,toc=-aa+cc;
					if(tob>=toc && tob>=abb.y && tob>=acc.y) pushb(i);
					else if(toc>=tob && toc>=abb.y && toc>=acc.y) pushc(i);
					else if(abb.y>=tob && abb.y>=toc && abb.y>=acc.y){
						d[abb.x]=2;
						ans+=abb.y;
						cntb++,cnta--;
						clearr();
						pusha(i);
					}
					else{
						d[acc.x]=3;
						ans+=acc.y;
						cntc++,cnta--;
						clearr();
						pusha(i);
					}
				}
			}
			else pusha(i);
		}
		else if(bb>=aa && bb>=cc){
			if(cntb>=m){
				if(bb==aa) pusha(i);
				else if(bb==cc) pushc(i);
				else{
					clearr();
					node baa,bcc;
					if(!ba.empty()) baa=ba.top();
					else baa=(node){0,-INF};
					if(!bc.empty()) bcc=bc.top();
					else bcc=(node){0,-INF};
					ll toa=-bb+aa,toc=-bb+cc;
					if(toa>=toc && toa>=baa.y && toa>=bcc.y) pusha(i);
					else if(toc>=toa && toc>=baa.y && toc>=bcc.y) pushc(i);
					else if(baa.y>=toa && baa.y>=toc && baa.y>=bcc.y){
						d[baa.x]=1;
						ans+=baa.y;
						cnta++,cntb--;
						clearr();
						pushb(i);
					}
					else{
						d[bcc.x]=3;
						ans+=bcc.y;
						cntc++,cntb--;
						clearr();
						pushb(i);
					}
				}
			}
			else pushb(i);
		}
		else{
			if(cntc>=m){
				if(cc==bb) pushb(i);
				else if(cc==aa) pusha(i);
				else{
					clearr();
					node cbb,caa;
					if(!cb.empty()) cbb=cb.top();
					else cbb=(node){0,-INF};
					if(!ca.empty()) caa=ca.top();
					else caa=(node){0,-INF};
					ll tob=-cc+bb,toa=-cc+aa;
					if(tob>=toa && tob>=cbb.y && tob>=caa.y) pushb(i);
					else if(toa>=tob && toa>=cbb.y && toa>=caa.y) pusha(i);
					else if(cbb.y>=tob && cbb.y>=toa && cbb.y>=caa.y){
						d[cbb.x]=2;
						ans+=cbb.y;
						cntb++,cntc--;
						clearr();
						pushc(i);
					}
					else{
						d[caa.x]=1;
						ans+=caa.y;
						cnta++,cntc--;
						clearr();
						pushc(i);
					}
				}
			}
			else pushc(i);
		}
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		while(!ab.empty()) ab.pop();
		while(!ac.empty()) ac.pop();
		while(!ba.empty()) ba.pop();
		while(!bc.empty()) bc.pop();
		while(!ca.empty()) ca.pop();
		while(!cb.empty()) cb.pop();
		memset(d,0,sizeof(d));
		ans=cnta=cntb=cntc=0;
		scanf("%lld",&n);
		m=n/2;
		for(ll i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		solve();
		printf("%lld\n",ans);
	}
	return 0;
}
