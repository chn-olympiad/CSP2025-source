#include<bits/stdc++.h>
#define P 40
#define mod 998244353
using namespace std;

typedef long long ll;
const int maxL = 1e6+10;
int maxl,l1,l2;
bool t[maxL];
ll pw[maxL],ret,c1,c2;
char s[maxL];
int n,p,cnt,ans;
map<pair<ll,ll>,int> id;
ll hs[maxL];//,hsr[maxL];
ll hs_[maxL];//,hsr_[maxL];

ll get(){
	ret = 0;
	cin >>(s+1);
	for(int i = 1;s[i];i ++) ret = (ret*P%mod + s[i])%mod;
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> p;
	pw[0] = 1;
	for(int i = 1;i < maxL;i ++) pw[i] = pw[i-1]*P%mod;
	
	for(int i = 1;i <= n;i ++){
		c1 = get();
		l1 = strlen(s+1);
		c2 = get();
		l2 = strlen(s+1);
		if(l1 != l2)continue;
		id[make_pair(c1,c2 )] = ++cnt;
	}
	
	
	for(int i = 1,j,sz;i <= p;i ++){
		ans = 0;
		for(int i = 1;i <= n;i ++) t[i] = true;
		cin >> (s+1);
		for(j = 1;s[j];j ++) hs[j] = (hs[j-1]*P + s[j])%mod; 
		sz = strlen(s+1);
		
		cin >> (s+1);
		for(j = 1;s[j];j ++) hs_[j] = (hs_[j-1]*P + s[j])%mod; 
		
		for(int l = 1,r,len,idd;s[l];l ++){
			for(r = l;s[r];r ++){
				if(hs[l-1] != hs_[l-1]) continue;
				if( (hs[sz]- hs[r]*pw[sz-r]%mod +mod)%mod != (hs_[sz]-hs_[r]*pw[sz-r]%mod+mod)%mod) continue;
				
				len = r-l+1;
				c1 = ( hs[r] -  hs[l-1]*pw[len]%mod + mod)%mod;
				c2 = (hs_[r] - hs_[l-1]*pw[len]%mod + mod)%mod;
				idd = id[make_pair(c1,c2)];
				if(t[idd]) ans ++,t[idd] = false;
			}
		}
		cout << ans <<'\n';
		
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

3 4
a b
b c
c d
aa bb
aa b
a c
b a


*/
