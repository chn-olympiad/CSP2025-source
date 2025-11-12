#include<iostream>
#include<algorithm>
#include<bitset>
using namespace std;

const int N=5e5+5;

int n,k;
int mn,mx;

int a[N],s[N];
bitset<N>vis;

int tot,ans;

struct node{
	int l,r;
}e[N];

inline int qry(int l,int r){
	return s[r]^s[l-1];
}

inline void getmx(int &a,int b){
	return a=(a>b?a:b),void();
}

inline void getmn(int &a,int b){
	return a=(a<b?a:b),void();
}

inline void solve(){
	for(int l=1;l<=n;++l){
		for(int r=l;r<=n;++r){
			if(qry(l,r)^k)continue ;
			else e[++tot]={l,r};
		}
	}
	if(tot)ans=1;
	else return cout<<0<<"\n",void();
	sort(e+1,e+tot+1,[](node a,node b){return (a.r==b.r)?(a.l>b.l):(a.r<b.r);});
	int lstr=e[1].r;
	for(int i=2;i<=tot;++i)if(e[i].l>lstr)++ans,lstr=e[i].r;
	return cout<<ans<<"\n",void();
}

inline void solveA(){
	return cout<<(n>>1)<<"\n",void();
}

inline void solveB(){
	if(k)for(int i=1;i<=n;++i)ans+=a[i];
	else for(int i=1;i<=n;++i)ans+=(!a[i]);
	return cout<<ans<<"\n",void();
}

inline void solveC(){
	return solve(),void();
}

signed main(){
	freopen("xor.in","r",stdin),freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>k;for(int i=1;i<=n;++i)cin>>a[i],getmx(mx,a[i]),getmn(mn,a[i]);
	s[1]=a[1];for(int i=2;i<=n;++i)s[i]=(s[i-1]^a[i]);
	if(n<=1e3)solve();
	else{
		if(mx==1&&mn==1)solveA();
		else if(mx<=1)solveB();
		else if(mx<=255)solveC();
		else solve();
	}
	return 0;
}
