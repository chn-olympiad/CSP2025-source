#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const __int128 MOD=100000000000000003; 
//1000000000039
string s1,s2;
string t1,t2;
mt19937 orz(time(NULL)); 
int n,q;
__int128 p[50];
ll ans;
map<__int128,int> f;
ll Pow(__int128 a,__int128 b){
	__int128 base=a;
	__int128 re=1;
	while(b){
		if(b&1){
			re*=base; 
			re%=MOD;
		}
		base*=base;
		base%=MOD;
		b>>=1;
	}
	return (ll)re;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i=1;i<=30;i++){
		p[i]=orz()%MOD;
		if(p[i]<=0) p[i]=-p[i]+1; 
	}
	for(int i=1;i<=n;i++){
		cin >> s1 >> s2; 
		if(s1==s2) continue;
		__int128 cnt1=0;
		for(int j=0;j<(int)s1.size();j++) cnt1=(cnt1*131%MOD+p[s1[j]-'a'+1])%MOD;
		__int128 cnt2=0;
		for(int j=0;j<(int)s2.size();j++) cnt2=(cnt2*131%MOD+p[s2[j]-'a'+1])%MOD;
		f[((cnt2-cnt1)%MOD+MOD)%MOD]++; 
	}
	while(q--){
		ans=0;
	    cin >> t1 >> t2;
	    if(t1.size()!=t2.size()){
	    	cout << 0 << endl;
	    	continue;
		}
	  	__int128 cnt1=0;
		for(int j=0;j<(int)t1.size();j++) cnt1=(cnt1*131%MOD+p[t1[j]-'a'+1])%MOD;
		__int128 cnt2=0;
		for(int j=0;j<(int)t2.size();j++) cnt2=(cnt2*131%MOD+p[t2[j]-'a'+1])%MOD;
		__int128 BASE=Pow(131,MOD-2);
		__int128 tg=((cnt2-cnt1)%MOD+MOD)%MOD;
		for(int i=1;i<=min((int)t1.size(),(int)t2.size());i++){
			ans+=f[tg];
			tg*=BASE;
			tg%=MOD;
		}
		cout << ans << endl;
	}
	
	return 0;
} 
