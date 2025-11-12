#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<ull,ull>;
const int base = 13331;
int n,q;
string s[MAXN][3];
ull d[MAXN][3];
map<pair<ull,ull>,vector<ull>> mp;
int main(){
#ifndef SVK
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>q;
	
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		if(s[i][1] == s[i][2])continue;
		int m = (int)s[i][1].size();
		int L=0, R=m-1;
		while(L<m && s[i][1][L] == s[i][2][L])L++;
		while(R>=0 && s[i][1][R] == s[i][2][R])R--;
		ull hsh = 0;
		for(int j=L;j<=R;j++){
			hsh=hsh*base+s[i][1][j];
			hsh=hsh*base+s[i][2][j];
		}
		ull Lsh = 0, Rsh = 0;
		for(int j=L-1;j>=0;j--)Lsh=Lsh*base+s[i][1][j];
		for(int j=R+1;j<m;j++)Rsh=Rsh*base+s[i][1][j];
		d[i][0] = hsh;
		d[i][1] = Lsh;
		d[i][2] = Rsh;
		mp[{hsh,Lsh}].push_back(Rsh);
	}
	
	while(q--){
		string a,b; cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<"0\n";
			continue;
		}
		int m = (int)a.size();
		int L=0, R=m-1;
		while(L<m &&  a[L] == b[L])L++;
		while(R>=0 && a[R] == b[R])R--;
		ull hsh = 0;
		for(int j=L;j<=R;j++){
			hsh=hsh*base+a[j];
			hsh=hsh*base+b[j];
		}
		set<ull> r; r.insert(0);
		ull Rsh = 0, Lsh=0;
		for(int j=R+1;j<m;j++)Rsh=Rsh*base+a[j], r.insert(Rsh);
		int ans = 0;
		auto calc = [&](){
			vector<ull>& v = mp[{hsh,Lsh}];
			for(ull x : v)ans += (int)r.count(x);	
		};
		calc();
		for(int i=L-1;i>=0;i--){
			Lsh = Lsh*base+a[i];
			calc();
		}
		cout<<ans<<"\n";
	}
	return 0;
}

