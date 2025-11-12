#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N = 100010;
struct node{
	ll a,b,c;
	ll zmax(){
		if(a>=b and a>=c)return 1;
		if(b>=a and b>=c)return 2;
		if(c>=a and c>=b)return 3;
		return 1;
	}
	ll cmax(){
		if(a>=b and b>=c)return 2;
		if(c>=b and b>=a)return 2;
		if(b>=a and a>=c)return 1;
		if(c>=a and a>=b)return 1;
		if(a>=c and c>=b)return 3;
		if(b>=c and c>=a)return 3;
		return 1;
	}
	ll g(ll x){
		if(x==1)return a;
		if(x==2)return b;
		if(x==3)return c;
		return a;
	}
}a[N];
ll n,m,tmp,ans;
bool cmp(node x,node y){
	if(x.g(x.zmax())+y.g(y.cmax())<=x.g(x.cmax())+y.g(y.zmax())){
		return 0;
	}
	return 1;
}
void solve(){ans=0;
	cin >> n;
	for(ll i=1;i<=n;i++){
		cin >> a[i].a >> a[i].b >> a[i].c;
	}
	ll b[5] = {0,0,0,0,0};
	sort(a+1,a+1+n,cmp);
	for(ll i=1;i<=n;i++){
		tmp = a[i].zmax();
		if(b[tmp]>=n/2){
			ans+=a[i].g(a[i].cmax());
			b[a[i].cmax()]++;
		}
		else{
			ans+=a[i].g(a[i].zmax());
			b[tmp]++;
		}
	}
	cout << ans << endl;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
