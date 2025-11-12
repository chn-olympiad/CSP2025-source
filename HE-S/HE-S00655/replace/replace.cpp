#include<bits/stdc++.h>
using namespace std;
#define int long long 

constexpr int maxn = 1e4+10;
int n, q;
constexpr int base = 131;
constexpr int mod = 1e9+9;
int bpow[maxn];
void initbow(){
	bpow[0] = 1;
	for(int i = 1;i < maxn;i++){
		bpow[i] = bpow[i-1] * base % mod;
	}
}
struct hstring{
	string s;
	vector<int> h;
	int n;
	void init(){
		n = s.size();
		h.assign(n+10,0);
		h[0] = 0;
		for(int i = 1;i <= n;i++){
			h[i] = (h[i-1] * base + s[i]) % mod;
		}
		
	}
	
	int gethash(int l,int r){
		if(r < l) return 0;
		int res =  (h[r] - h[l-1] * bpow[r - l + 1] % mod + mod) % mod; 
		return res;
	}
};

hstring t1[maxn], t2[maxn];

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	initbow();
	cin>>n>>q;
	for(int i = 1;i <= n;i++){
		cin>>t1[i].s>>t2[i].s;
		t1[i].s = " " + t1[i].s;
		t2[i].s = " " + t2[i].s;
		t1[i].init();
		t2[i].init();
	}
	while(q--){
		hstring s1, s2;
		cin>>s1.s>>s2.s;
		s1.s = " " + s1.s;
		s2.s = " " + s2.s;
		s1.init();
		s2.init();
		int ans = 0;
		for(int i = 1;i <= n;i++){
			int tlen = t1[i].s.length()-1;
			auto t1hash = t1[i].gethash(1,t1[i].s.length()-1);
			auto t2hash = t2[i].gethash(1,t2[i].s.length()-1);
			for(int pos = 1;pos + tlen -1 < (int)s1.s.length();pos++){
			
				if(s1.gethash(pos,pos+tlen - 1) ==  t1hash
				&& s2.gethash(pos,pos+tlen - 1) == t2hash
				&& s1.gethash(1,pos-1) == s2.gethash(1,pos-1)
				&& s1.gethash(pos+tlen,s1.s.length()-1) == s2.gethash(pos+tlen,s2.s.length()-1)){
					ans++;
				}
			} 
		}
		cout<<ans<<endl;
	}
	return 0;
}

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
