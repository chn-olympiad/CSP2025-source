#include<bits/stdc++.h>
#define i1 __int128
#define int long long 
using namespace std;
struct _queue{
	int a[1000005],head=1,tail;
	int _front(){return a[head];}
	bool _empty(){return tail<head;}
	void _push(int x){a[++tail]=x;}
	void _pop(){head++;}
};
struct _stack{
	int a[1000005],head;
	int _top(){return a[head];}
	bool _empty(){return head;}
	void _push(int x){a[++head]=x;}
	void _pop(){head--;}
};
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
const int mod=(int)1e17+19,base=53,L=5e6+5,N=2e5+5;
int fac[L],inv[L];
int qpow(i1 a,int b){
	i1 s=1;
	while(b){
		if(b&1) s=s*a%mod;
		a=a*a%mod,b>>=1;
	}
	return (int)s;
}
void init(){
	fac[0]=1;
	for(int i=1;i<L;i++) fac[i]=fac[i-1]*base%mod;
	inv[L-1]=qpow(fac[L-1],mod-2);
	for(int i=L-2;i>=0;i--) inv[i]=inv[i+1]*base%mod;
}
struct String{
	string s;
	int len;
	vector<int>_hash;
	void ghash(){
		_hash.clear();
		len=s.size();
		s=' '+s;
		_hash.push_back(0);
		for(int i=1;i<=len;i++) _hash.push_back((_hash[i-1]+(s[i]-'a')*fac[i])%mod);
	}
	int gs(int x,int y){return (i1)(_hash[y]-_hash[x]+mod)%mod*inv[x]%mod;}
};
String s1[N],s2[N],x,y;
int n,q;
bool check(int id,int pos){
	bool f=1;
	f&=x.gs(pos,pos-s1[id].len)==s1[id].gs(s1[id].len,0);
	f&=y.gs(pos,pos-s2[id].len)==s2[id].gs(s2[id].len,0);
	f&=x.gs(pos-s1[id].len,0)==y.gs(pos-s2[id].len,0);
	f&=x.gs(x.len,pos)==y.gs(y.len,pos);
	return f;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	init();
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		cin>>s1[i].s>>s2[i].s;
		s1[i].ghash();
		s2[i].ghash();
	}
	while(q--){
		cin>>x.s>>y.s;
		x.ghash();
		y.ghash();
		if(x.len!=y.len){
			cout<<"0\n";
			continue ;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=s1[i].len;j<=x.len;j++)
				if(check(i,j)){
					ans++;
					break ;
				}
		cout<<ans<<'\n';
	}
	return 0;
}

