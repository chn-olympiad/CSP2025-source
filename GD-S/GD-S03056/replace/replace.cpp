#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200005,maxl=5000006;
const int mod=531902729,pa=131;
inline int ad(int x,int y){return x+=y,(x>=mod)?(x-mod):x;}
inline void adt(int &x,int y){x+=y;(x>=mod)&&(x-=mod);}
inline int su(int x,int y){return ad(x,mod-y);}
inline void sut(int &x,int y){adt(x,mod-y);}
int n,q;
struct Rep{
	string s[2];int h[2],len;
	bool operator <(const Rep &qyy)const{return len<qyy.len;}
}a[maxn];
string t[2];int L,R,f[2][maxl];
namespace Hash{
	int pw[maxl];
	inline void Hinit(){pw[0]=1;for(int i=1;i<maxl;i++) pw[i]=1ll*pw[i-1]*pa%mod;}
	inline int calc(int l,int r,int id){return su(f[id][r],1ll*f[id][l-1]*pw[r-l+1]%mod);}
//	inline int calc(int l,int r,int (&ha)[]){return su(ha[r],1ll*ha[l-1]*pw[r-l+1]%mod);}
}using namespace Hash;
inline bool chk(int r,int i){return (calc(r-a[i].len+1,r,0)==a[i].h[0]&&calc(r-a[i].len+1,r,1)==a[i].h[1]);}
int solve(){
	const int let=t[0].size();
	for(int j=0;j<2;j++){
		for(int k=0;k<let;k++) f[j][k]=ad(1ll*((k>0)?f[j][k-1]:0)*pa%mod,t[j][k]-'a');
	}
	L=let,R=0;
	for(int i=0;i<let;i++) if(t[0][i]!=t[1][i]){L=i;break;}
	for(int i=let-1;i>=0;i--) if(t[0][i]!=t[1][i]){R=i;break;}
	int res=0,liz=1;
	for(int i=R;i<let;i++){
		while(liz<=n&&a[liz].len<(i-L+1)) liz++;
		if(liz>n) break;
		for(int j=liz;j<=n;j++){
			if(a[j].len>i+1) break;
			res+=chk(i,j);
		}
	}
	return res;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;Hinit();
	for(int i=1;i<=n;i++){cin>>a[i].s[0]>>a[i].s[1];a[i].len=a[i].s[0].size();}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<a[i].len;k++) a[i].h[j]=ad(1ll*a[i].h[j]*pa%mod,a[i].s[j][k]-'a');
		}
	}
	for(int i=1;i<=q;i++){
		cin>>t[0]>>t[1];
		cout<<solve()<<'\n';
	}
	return 0;
}
/*
4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
*/
//power!!!!
