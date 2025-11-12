#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);++i)
#define per(i,a,n) for(int i=(n);i>=(a);--i)
#define SZ(x) ((int)x.size())

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn=2e5+10,base=131,maxm=5e6+10;

inline int rd(){
	char ch=getchar();
	bool w=false;
	int x=0;
	while(!isdigit(ch)){
		w|=ch=='-';
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	if(w) x=-x;
	return x;
}

int n,q,pr[maxn],sf[maxn];
string s[2][maxn],t[2][maxn];
mt19937_64 rnd(0);
ull val[200],pres[maxn],sufs[maxn],vs[maxn],pret[maxn],suft[maxn],vt[maxn],pw[maxm];
bool del[maxn];

inline void solve(){
	n=rd(); q=rd();
	rep(i,1,n){
		char ch=getchar();
		while(ch>='a' && ch<='z'){
			s[0][i].push_back(ch);
			ch=getchar();
		}
		ch=getchar();
		while(ch>='a' && ch<='z'){
			s[1][i].push_back(ch);
			ch=getchar();
		}
	}
	pw[0]=1;
	rep(i,1,5e6) pw[i]=pw[i-1]*base;
	rep(i,1,q){
		char ch=getchar();
		while(ch>='a' && ch<='z'){
			t[0][i].push_back(ch);
			ch=getchar();
		}
		ch=getchar();
		while(ch>='a' && ch<='z'){
			t[1][i].push_back(ch);
			ch=getchar();
		}	
	}
	rep(i,'a','z') val[i]=rnd();
	rep(i,1,n){
		int len=SZ(s[0][i]);
		int j=-1,k=len;
		while(j+1<len){
			if(s[0][i][j+1]==s[1][i][j+1]) 
				j++;
			else break;
		}
		while(k-1>=0){
			if(s[0][i][k-1]==s[1][i][k-1])
				k--;
			else break;
		}
		if(j==len-1 || k==0){
			del[i]=true;
			continue;	
		}
		pr[i]=j+1; sf[i]=len-k;
		per(o,0,j) pres[i]=pres[i]*base+(s[1][i][o]-'a'+1);
		rep(o,k,len-1) sufs[i]=sufs[i]*base+(s[1][i][o]-'a'+1);
		rep(o,j+1,k-1) vs[i]=vs[i]*base+(val[s[1][i][o]]-val[s[0][i][o]]);
	}
	rep(i,1,q){
		int len=SZ(t[0][i]);
		int j=-1,k=len;
		while(j+1<len){
			if(t[0][i][j+1]==t[1][i][j+1]) 
				j++;
			else break;
		}
		while(k-1>=0){
			if(t[0][i][k-1]==t[1][i][k-1])
				k--;
			else break;
		}
//		printf("%d %d %d\n",i,j,k);
		pret[j+1]=suft[k-1]=0;
//		rep(o,0,j) pret[i]=pret[i]*base+(t[1][o]-'a'+1);
//		per(o,k,len) suft[i]=suft[i]*base+(t[1][o]-'a'+1);
		per(o,0,j) pret[o]=pret[o+1]*base+(t[1][i][o]-'a'+1);
		rep(o,k,len-1) suft[o]=suft[o-1]*base+(t[1][i][o]-'a'+1);
		rep(o,j+1,k-1) vt[i]=vt[i]*base+(val[t[1][i][o]]-val[t[0][i][o]]);
		int res=0;
		auto querypr=[&](int l,int r)->ull{
			if(l>r) return 0;
			return pret[l]-pret[r+1]*pw[r-l+1];
		};
		auto querysf=[&](int l,int r)->ull{
			if(l>r) return 0;
			return suft[r]-suft[l-1]*pw[r-l+1];
		};		
		rep(p,1,n){
			if(vs[p]!=vt[i] || del[p]) continue;
			int tpr=j+1,tsf=len-k;
			if(pr[p]>tpr || sf[p]>tsf) continue;
//			printf("# %d %d %llu %llu %llu %llu\n",i,p,pres[p],querypr(j-pr[p]+1,j),sufs[p],querysf(k,k+sf[p]-1));
			if(querypr(j-pr[p]+1,j)==pres[p] && querysf(k,k+sf[p]-1)==sufs[p])
				res++;
		}
		printf("%d\n",res);
	}
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int _=1;
//	scanf("%d",&_);
	while(_--) solve();
}

