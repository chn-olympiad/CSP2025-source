#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q;
string s,t;
ll Base = 1331 , Mod = 1e9 + 7;
map<ll,map<ll,int> > m;
void slvsub1(){
	ll l=0,r;
	while(s[l] == t[l] && l < s.size()) l++;
	r = l;
	while(s[r+1] != t[r+1] && r + 1 < s.size()) r++;
	ll ans = 0;
	for(int i=0;i<=l;i++){
		ll A = 0 , B = 0 , k = 1;
		for(int j=i;j<s.size();j++){
			A = A + (s[j] - 96) * k;
			A %= Mod;
			B = B + (t[j] - 96) * k;
			B %= Mod;
			k = k * Base % Mod;
			if(j >= r) ans += m[A][B];
		}
	}
	cout<<ans<<"\n";
	return ;
}
struct N{
	ll l,k;
	ll id;
} a[200005],c[200005]; 
bool cmp(N x,N y){
	if(x.k == y.k) return x.l < y.l;
	return x.k < y.k;
}
ll ans[200005];
int ts[5000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(q <= 1000){
		for(int i=1;i<=n;i++){
			cin>>s>>t;
			ll A = 0 , B = 0 , k = 1;
			for(int j=0;j<s.size();j++){
				A = A + (s[j] - 96) * k;
				A %= Mod;
				B = B + (t[j] - 96) * k;
				B %= Mod;
				k = k * Base % Mod;
			}
			m[A][B]++;
		}
		while(q--){
			cin>>s>>t;
			if(s.size() != t.size()){
				cout<<0<<"\n";
				continue;
			}
			slvsub1();
		}
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>s>>t;
			ll A = 0, B = 0;
			while(s[A] != 'b' && A < s.size()) A++;
			while(t[B] != 'b' && B < t.size()) B++;
			a[i] = N{A-1,A-B,0};
		}
		ll z = 0;
		while(q--){
			cin>>s>>t;
			ll A = 0, B = 0;
			while(s[A] != 'b' && A < s.size()) A++;
			while(t[B] != 'b' && B < t.size()) B++;
			c[++z] = N{A-1,A-B,z};
		}
		sort(a+1,a+n+1,cmp);
		memset(ts,0x3f3f3f,sizeof(ts));
		for(int i=1;i<=n;i++){
			ts[a[i].k + 2000000] = min(ts[a[i].k + 2000000] , i);
		}
		sort(c+1,c+z+1,cmp);
		ll j = 1;
		for(int i=1;i<=z;i++){
			while(a[j].k != c[i].k && j <= n) j++;
			if(j == n + 1){ans[c[i].id] = 0;continue;}
			while(a[j].l <= c[i].l && j <= n) j++;
			j -= 1;
			ans[c[i].id] = j - ts[a[j].k + 2000000] + 1;
		}
		for(int i=1;i<=z;i++) cout<<ans[i]<<"\n";
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
