#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5,M = 5e6+5,B = 616673,mod = 1e9+7;
int fpow(int a,int b){
	a%=mod;
	int ans = 1;
	while(b){
		if(b%2)ans = ans*a%mod;
		a = a*a%mod;
		b/=2;
	}
	return ans;
}
int n,q,ps1,ps2,ny[M],pw[M],hsh[2][M],lt[N],rt[N],ls,rs,ans,a1[N],b1[N],a2[N],b2[N],sz[N];
string s,t;
int qs(int l,int r,int f){
	return (hsh[f][r]-hsh[f][l-1]+mod)%mod*ny[l-1]%mod;
}
map<pair<int,int>,vector<int> >mp;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	pw[0] = ny[0] = 1;
	ny[1] = fpow(B,mod-2);
	for(int i = 2;i<=2e5;i++)ny[i] = ny[i-1]*ny[1]%mod;
	for(int i = 1;i<=2e5;i++)pw[i] = pw[i-1]*B%mod;
	for(int i = 1;i<=n;i++){
		cin >> s;
		sz[i] = s.size();
		ps1 = 0;
		s = " "+s;
		for(int j = 1;j<s.size();j++){
			ps1 = (ps1+(s[j]-'a'+1)*pw[j]%mod)%mod;
		}
		a1[i] = ps1;
		cin >> t;
		ps2 = 0;
		t = " "+t;
		for(int j = 1;j<t.size();j++){
			ps2 = (ps2+(t[j]-'a'+1)*pw[j]%mod)%mod;
		}
		b1[i] = ps2;
		for(int j = 1;j<s.size();j++){
			if(s[j]!=t[j]){
				lt[i] = j;
				break;
			}
		}
		for(int j = 1;j<s.size();j++){
			if(s[j]!=t[j])rt[i] = j;
		}
		ps1 = 0;
		for(int j = lt[i];j<=rt[i];j++){
			ps1 = (ps1+(s[j]-'a'+1)*pw[j-lt[i]+1]%mod)%mod;
		}
		a2[i] = ps1;
		ps2 = 0;
		for(int j = lt[i];j<=rt[i];j++){
			ps2 = (ps2+(t[j]-'a'+1)*pw[j-lt[i]+1]%mod)%mod;
		}
		b2[i] = ps2;
		mp[{a2[i],b2[i]}].push_back(i);
	}
	while(q--){
		cin >> s >> t;
		s = " "+s;
		t = " "+t;
		if(s.size()!=t.size()){
			cout << "0\n";
			continue;
		}
		for(int i = 1;i<s.size();i++){
			if(s[i]!=t[i]){
				ls = i;
				break;
			}
		}
		for(int i = 1;i<s.size();i++){
			if(s[i]!=t[i])rs = i;
		}
		for(int i = 1;i<s.size();i++){
			hsh[0][i] = (hsh[0][i-1]+(s[i]-'a'+1)*pw[i]%mod)%mod;
		}
		for(int i = 1;i<t.size();i++){
			hsh[1][i] = (hsh[1][i-1]+(t[i]-'a'+1)*pw[i]%mod)%mod;
		}
		ans = 0;
		for(auto i:mp[{qs(ls,rs,0),qs(ls,rs,1)}]){
			if(ls-lt[i]+1<1||rs+(sz[i]-rt[i])>s.size()-1)continue;
			if(qs(ls-lt[i]+1,rs+(sz[i]-rt[i]),0)!=a1[i])continue;
			if(qs(ls-lt[i]+1,rs+(sz[i]-rt[i]),1)!=b1[i])continue;
			ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
