#include <bits/stdc++.h>

#define ll long long
#define pii pair<ll,ll>
#define multicase() int t;cin>>t;while(t--)
using namespace std;
//using pii = pair<ll,ll>;
//using ll = long long;

const ll kMaxN = 1e5 + 7;

struct node{
	ll val , id;
	bool operator<(const node &a)const {
		return val > a.val;
	}
}va[kMaxN] , vb[kMaxN] , vc[kMaxN];

bool cmp(node a , node b){
	return a.val < b.val;
}

ll a[kMaxN][7];
ll n;

ll bt[kMaxN];

void solve(){
	cin>>n;
	for(int i = 1 ; i <= n ; i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		va[i].id = i , va[i].val = a[i][1];
		vb[i].id = i , vb[i].val = a[i][2];
		vc[i].id = i , vc[i].val = a[i][3];
	}
	ll tota , totb , totc;
	tota = totb = totc = 0;
	ll useda , usedb , usedc;
	useda = usedb = usedc =0;
	ll tus = n / 2;
//	cout<<"sa";
	sort(va + 1 , va + 1 + n);
	sort(vb + 1 , vb + 1 + n);
	sort(vc + 1 , vc + 1 + n);
	ll ans = 0;
	for(int i = 1 ; i <= n ; i++){
		if(tus == useda) break;
//		cout<<"sa";
		tota++;
//		cout<<va[tota].id<<" ";
		bt[va[tota].id] = 1;
		ans += va[tota].val;
	}
//	cout<<"sa";
	for(int i = 1 ; i <= n ; i++){
		if(tus == usedb) break;
		totb++;
		cout<<"s";
		if(bt[vb[totb].id]){
			cout<<"b";
			ll nxta = tota;
			while(bt[va[nxta].id] && nxta < n) {cout<<nxta;nxta++;}
			if(nxta == tota || nxta > n) continue;
			
			cout<<"sdadasd";

			ll dta = vb[totb].val - a[vb[totb].id][bt[vb[totb].id]] + va[nxta].val;

			if(dta > 0){
				cout<<"sdsadas";
				ans += dta;
//				tota++;
				bt[vb[totb].id] = 2;
				bt[va[nxta].id] = 1;
			}else{
				cout<<"c";
//				continue;
			}				
		}else{
			bt[vb[totb].id] = 2;
			ans += vb[totb].val;
		}
	}
	for(int i = 1 ; i <= n ; i++){
		if(tus == usedc) break;
		totc++;
		if(bt[vc[totc].id]){
			ll nxta = tota;
			while(bt[va[nxta].id]) nxta++;
			ll dta = vc[totc].val - a[vc[totc].id][bt[vc[totc].id]] + va[nxta].val;
			ll nxtb = totb;
			while(bt[vc[nxtb].id]) nxtb++;
			ll dtb = vc[totc].val - a[vc[totc].id][bt[vc[totc].id]] + vb[nxtb].val;
			if(dta > dtb){
				ans += dta;
				tota++;
				bt[vc[totc].id] = 3;
				bt[va[nxta].id] = 1;		
			}
			if(dtb > dta){
				ans += dtb;
				totb++;
				bt[vc[totc].id] = 3;
				bt[va[nxtb].id] = 2;
			}
			if(dta == dtb){
				if(tota < totb){
					ans += dta;
					tota++;
					bt[vc[totc].id] = 3;
					bt[va[nxta].id] = 1;
				}else{
					ans += dtb;
					totb++;
					bt[vc[totc].id] = 3;
					bt[va[nxtb].id] = 2;
				}
			}
		}
		
	}
	cout<<ans;
}

int main(){
	multicase(){
		solve();
		cout<<"\n";
	}
	return 0;
}
