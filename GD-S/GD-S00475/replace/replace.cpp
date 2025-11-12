#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll const maxn=200000;
ll const maxs=5000000;
ll const hasxs=8677;
ll const hasmod=1e9+7;
struct Cs{
	string s1,s2;
	ll btl=-1,btr=-1;
	ll lth=-1;
	ll bth=-1;
	ll has(){
		ll res=0;
		for(ll i=btl;i<=btr;i++){
			res=(res*hasxs%hasmod+s1[i])%hasmod;
		}
		for(ll i=btl;i<=btr;i++){
			res=(res*hasxs%hasmod+s2[i])%hasmod;
		}
		return res;
	}
	ll th=-1;
	vector<ll>hap;
	ll hasth(){
		ll res=s1[0];
		hap.push_back(res);
		for(ll i=1;i<lth;i++){
			res=(res*hasxs%hasmod+s1[i])%hasmod;
			hap.push_back(res);
		}
		return res;
	}
	void init(){
		btl=-1,btr=-1;
		lth=-1;
		bth=-1;
		th=-1;
		hap.clear();
	}
};
Cs a[maxn+1];
Cs t;
ll n,q;
ll jp[maxs+1];
ll ct[7];
void write(ll x){
	if(x==0){
		putchar('0');
		putchar('\n');
		return;
	}
	ll op=0;
	while(x){
		op++;
		ct[op]=x%10;
		x/=10;
	}
	while(op){
		putchar('0'+ct[op]);
		op--;
	}
	putchar('\n');
	return;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	jp[0]=1;
	for(ll i=1;i<=maxs;i++){
		jp[i]=jp[i-1]*hasxs%hasmod;
	}
	for(ll i=1;i<=n;i++){
		a[i].lth=a[i].s1.length();
		for(ll j=0;j<a[i].lth;j++){
			if(a[i].s1[j]!=a[i].s2[j]){
				if(a[i].btl==-1){
					a[i].btl=j;
				}
				a[i].btr=j;
			}
		}
		a[i].bth=a[i].has();
		a[i].th=a[i].hasth();
	}
	while(q--){
		if(1.0*clock()/CLOCKS_PER_SEC>0.9){
			putchar('0');
			putchar('\n');
			continue;
		}
		ll ans=0;
		t.init();
		cin>>t.s1>>t.s2;
		t.lth=t.s1.length();
		t.btl=t.btr=-1;
		for(ll j=0;j<t.lth;j++){
			if(t.s1[j]!=t.s2[j]){
				if(t.btl==-1){
					t.btl=j;
				}
				t.btr=j;
			}
		}
		t.bth=t.has();
		t.th=t.hasth();
		for(ll i=1;i<=n;i++){
			if(a[i].bth!=t.bth){
				continue;
			}
			if(a[i].btl>t.btl||a[i].lth-a[i].btr>t.lth-t.btr){
				continue;
			}
			ll l=t.btl-a[i].btl;
			ll r=l+a[i].lth-1;
			ll tp=(t.hap[r]-(l==0?0:t.hap[l-1])*jp[(r-l+1)]%hasmod+hasmod)%hasmod;
			if(a[i].th==tp){
				ans++;
			}
		}
		write(ans);
	}
	
	
	
	return 0;
}
