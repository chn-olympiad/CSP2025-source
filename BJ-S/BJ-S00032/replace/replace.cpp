#include<bits/stdc++.h>
#define int long long
using namespace std;
using Pair=pair<int,int>;
constexpr int N=1e5+5,M_=5e6+5,MAX=0x3fff'ffff'ffff'ffff,P=998244353,P2=10007;
namespace{
	int Pow(int a,int k){
		if(a<0||a>=P) a=(a%P+P)%P;
		if(k<0||k>=P-1) k=(k%(P-1)+(P-1))%(P-1);
		int ans=1;
		while(k){
			if(k&1) (ans*=a)%=P;
			(a*=a)%=P; k>>=1;
		}
		return ans;
	}
	int Inv(int a){return Pow(a,P-2);}
	int Pow_[M_+5],IPow[M_+5];
	void Init(int n){
		Pow_[0]=1; for(int i=1;i<=n;i++) Pow_[i]=Pow_[i-1]*P2%P;
		int I=Inv(P2);
		IPow[0]=1; for(int i=1;i<=n;i++) IPow[i]=IPow[i-1]*I%P;
	}
}
struct Str{
	string s;
	vector<int> H;
	int HashVal(int l,int r)const{
		return (H[r]-(l==0?0:H[l-1])+P)%P*IPow[l]%P;
	}
	int size()const{return s.size();}
	void build(){
		H.resize(s.size());
		H[0]=s[0];
		for(int i=1;i<H.size();i++) H[i]=(H[i-1]+s[i]*Pow_[i]%P)%P;
	}
	Str(const string &S){
		s=S; build();
	}
};
struct Info{
	int fstdiff,lstdiff,val;
};
struct Info2{
	Str a,b;
	Info info;
};
Info diffHash(const Str &a,const Str &b){
	int fstdiff=-1,lstdiff=-1,n=a.size();
	for(int i=0;i<n;i++) if(a.s[i]!=b.s[i]){
		if(fstdiff==-1) fstdiff=i;
		lstdiff=i;
	}
	if(fstdiff==-1) return {-1,-1,0};
	return {fstdiff,lstdiff,(a.HashVal(fstdiff,lstdiff)*114514+b.HashVal(fstdiff,lstdiff))%P};
}
int n,q;
unordered_map<int,vector<Info2>> M;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>q; Init(M_);
	for(int i=1;i<=n;i++){
		string s1,s2; cin>>s1>>s2;
		Str a(s1),b(s2); auto tmp=diffHash(a,b);
		M[tmp.val].push_back({s1,s2,tmp});
	}
	for(int i=1;i<=q;i++){
		string s1,s2; cin>>s1>>s2;
		Str a(s1),b(s2); auto tmp=diffHash(a,b);
		const auto &vec=M[tmp.val];
		int cnt=0;
		for(const auto &[s,t,info]:vec){
			if(info.fstdiff<=tmp.fstdiff&&tmp.fstdiff-info.fstdiff+s.size()<=a.size()){
				if(s.HashVal(0,s.size()-1)==a.HashVal(tmp.fstdiff-info.fstdiff,tmp.fstdiff-info.fstdiff+s.size()-1)){
					cnt++;
				}
			}
		}
		cout<<cnt<<'\n';
	}
}