#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define i128 __int128
#define _rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define _per(i,a,b) for(ll i=(a);i>=(b);i--)
#define ckmax(a,b) a=max((ll)(a),(ll)(b))
#define ckmin(a,b) a=min((ll)(a),(ll)(b))
#define PII pair<int,int>
#define fi first
#define se second
#define _add(x,y) x=(((ll)(x)+(y))%mod+mod)%mod
#define _mul(x,y) x=(((ll)(x)*(y))%mod+mod)%mod
#define dbg(x) cout<<#x<<'='<<x<<'\n'
#define ptc putchar

ll rd(){
	ll res=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*f;
}
void wr(ll x){
	if(x<0) x=-x,ptc('-');
	if(x>9) wr(x/10);
	ptc(x%10+'0');
}

int T=1;
int n,m;
string s1,s2;
set<pair<string,string>> s;

void sol(){
	n=rd(),m=rd();
	_rep(i,1,n){
		cin>>s1>>s2;
		s.insert({s1,s2});
	}
	_rep(i,1,m){
		cin>>s1>>s2;
		int len1=s1.size(),len2=s2.size();
		string t1,t2;
		puts("0"); 
//		_rep()
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	T=rd();
	while(T--) sol();
	return 0;
}
