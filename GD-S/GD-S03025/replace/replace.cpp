#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
const int N=2e5+5,L=5e6+5;
//char ccc1;
int n,q;
//char ccc3;
char s[L],t[L];
vector<ll> op[L]; 
int tot;
int tr[L][26];
int fail[L];
int rt[L];
ll base=131;
int hd,tl;
int d[L];
ll inv[L];
ll qpow(ll x,int y){
	ll res=1;
	while(y){
		if(y&1){
			res=res*x%mod;
		}
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
struct seg{
	int tot;
	struct node{
		int num;
		int ls,rs;
	}t[30*N];
	int upd(int x,int l,int r,int d){
		int nw=++tot;
		t[nw]=t[x];
		if(l==r){
			t[nw].num++;
			return nw;
		}
		int mid=(l+r)/2;
		if(d<=mid){
			t[nw].ls=upd(t[nw].ls,l,mid,d);
		}else{
			t[nw].rs=upd(t[nw].rs,mid+1,r,d);
		}
		return nw;
	}
	int qry(int x,int l,int r,int d){
		if(x==0) return 0;
		if(l==r){
			return t[x].num;
		}
		int mid=(l+r)/2;
		if(d<=mid){
			return qry(t[x].ls,l,mid,d); 
		}else{
			return qry(t[x].rs,mid+1,r,d);
		}
	}
}T;
//char ccc2;
//
void bd(){
	hd=tl=0;
	for(int i=0; i<26; i++){
		if(tr[0][i]){
			d[++tl]=tr[0][i];
		}
	}
	while(hd<tl){
		hd++;
		int p=d[hd];
		for(int i=0; i<26; i++){
			if(!tr[p][i]){
				tr[p][i]=tr[fail[p]][i];
			}else{
				fail[tr[p][i]]=tr[fail[p]][i];
				d[++tl]=tr[p][i];
			}
		}
	}
	for(int i=1; i<=tl; i++){
		int ii=d[i];
		rt[ii]=rt[fail[ii]];
		for(int j=0; j<(int)op[ii].size(); j++){
			rt[ii]=T.upd(rt[ii],0,mod-1,op[ii][j]);
		}
	}
	return;
}

void init(){
	ll ib=qpow(base,mod-2);
	inv[0]=1;
	for(int i=1; i<=5e6; i++){
		inv[i]=inv[i-1]*ib%mod;
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	cerr<<(&ccc2)-(&ccc1)<<" "<<(&ccc3)-(&ccc1);
	scanf("%d%d",&n,&q);
	init();
	for(int i=1; i<=n; i++){
		scanf("%s",s+1);
		int len=strlen(s+1);
		scanf("%s",t+1);
		int p=0;
		ll hs1=0,hs2=0;
		for(int j=1; j<=len; j++){
			hs1=(hs1*base+s[j])%mod;
			hs2=(hs2*base+t[j])%mod;
		}
		for(int j=1; j<=len; j++){
			int c=s[j]-'a';
			if(tr[p][c]==0) tr[p][c]=++tot;
			p=tr[p][c];
		}
		op[p].push_back((hs2-hs1+mod)%mod);
	}
	for(int i=0; i<=tot; i++){
		rt[i]=++T.tot;
	}
	bd();
	while(q--){
		scanf("%s",s+1);
		scanf("%s",t+1);
		int lens=strlen(s+1);
		int lent=strlen(t+1);
		if(lens!=lent){
			printf("0\n");
			continue;
		}
		ll hs1=0,hs2=0;
		ll df=0;
		for(int i=1; i<=lens; i++){
			hs1=(hs1*base+s[i])%mod;
			hs2=(hs2*base+t[i])%mod;
			if(s[i]!=t[i]){
				df=i;
			}
		}
		int p=0;
		int ans=0;
		for(int i=1; i<=lens; i++){
			int c=s[i]-'a';
			p=tr[p][c];
			if(i>=df){
				ll res=(hs2-hs1+mod)*inv[lens-i]%mod;
				res=(res+mod)%mod;
				ans+=T.qry(rt[p],0,mod-1,res);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
