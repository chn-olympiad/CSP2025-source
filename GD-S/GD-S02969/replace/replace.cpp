#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long ll;
const ll mod=1e13+3,bs1=163,bs2=167;
string s1[N],s2[N];
int n,m;
struct node {
	ll a1,a2,b1,b2;
};
bool operator < (node x,node y) {
	if(x.a1==y.a1) {
		if(x.a2==y.a2) {
			if(x.b1==y.b1)
				return x.b2<y.b2;
			return x.b1<y.b1;
		}
		return x.a2<y.a2;
	}
	return x.a1<y.a1;
}
map<node,int> mp;
ll h1(string &s) {
	ll res=0;
	for(int i=0;i<(int)s.length();i++) {
		res=(res*bs1+s[i])%mod;
	}
	return res;
}
ll h2(string &s) {
	ll res=0;
	for(int i=0;i<(int)s.length();i++) {
		res=(res*bs2+s[i])%mod;
	}
	return res;
}
void solve() {
	string t1,t2;  cin>>t1>>t2;
	int len=t1.length();
	if(len!=(int)t2.length()) {cout<<0<<"\n";}
	int nl=-1,nr=-1;
	for(int i=0;i<len;i++) {
		if(t1[i]!=t2[i]) {
			if(nl==-1) 
				nl=i;
			nr=i;
		}
	}
	ll ans=0;
	for(int i=0;i<=nl;i++) {
		ll a11=0,a12=0,a21=0,a22=0;
		for(int j=i;j<len;j++) {
			a11=(a11*bs1+t1[j])%mod;
			a12=(a12*bs2+t1[j])%mod;
			a21=(a21*bs1+t2[j])%mod;
			a22=(a22*bs2+t2[j])%mod;
			if(j>=nr) {
				if(mp.find({a11,a12,a21,a22})!=mp.end()) {
					ans+=mp[{a11,a12,a21,a22}];
//					cout<<a11<<" "<<a12<<" "<<a21<<" "<<a22<<endl;
				}
			}
		}
	}
	cout<<ans<<endl;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>s1[i]>>s2[i];
		ll a11=h1(s1[i]), a12=h2(s1[i]), a21=h1(s2[i]), a22=h2(s2[i]);
		mp[{a11,a12,a21,a22}]++;
//		cout<<a11<<" "<<a12<<" "<<a21<<" "<<a22<<endl;
	}
//	cout<<endl;
//	for(pair<node,int> tmp1:mp) {
//		node tmp=tmp1.first;
//		cout<<tmp.a1<<" "<<tmp.a2<<" "<<tmp.b1<<" "<<tmp.b2<<" ; "<<tmp1.second<<endl;
//	}
	while(m--) {
		solve();
	}
}

