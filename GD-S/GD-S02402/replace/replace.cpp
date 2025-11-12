#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e15+37,bs=131;
const int N=2e5+15,M=5e6+15;
inline ll read(){
	ll x=0;char f=1,c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=0;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0',c=getchar();}
	return f?x:-x;
}
int n,q,L1,L2,sl[N],sr[N],tl[N],tr[N],lens[N],lent[N];
ll pw[M];
char s[2][M],t[2][M];
ll hs[2][M],ht[2][M];
map<pair<ll,ll>,int>cnt[1005];
inline ll gs(int op,int id,int l,int r){
	if(l>r)return -1;
	return (hs[op][sl[id]+r-1]-(l!=1?hs[op][sl[id]+l-2]:0)*pw[r-l+1]%mod+mod)%mod;
}
inline ll gt(int op,int id,int l,int r){
	if(l>r)return -1;
	return (ht[op][tl[id]+r-1]-(l!=1?ht[op][tl[id]+l-2]:0)*pw[r-l+1]%mod+mod)%mod;
}
inline bool ck(char*s,int l,int r){
	bool flg=0;
	for(int i=l;i<=r;++i){
		if(s[i]!='a'&&s[i]!='b')return 0;
		if(s[i]=='b'){
			if(flg==1)return 0;
			flg=1;
		}
	}
	return flg;
}
bool A=1,B=1;
int pb[N],sb[N],gb[N];//pre,suf,gap
int solve(){
	n=read(),q=read();
	A=(q==1);
	for(int i=1;i<=n;++i){
		sl[i]=sr[i-1]+1;
		scanf("%s%s",s[0]+sl[i],s[1]+sl[i]);
		sr[i]=sl[i]+(lens[i]=strlen(s[0]+sl[i]))-1;
		hs[0][sl[i]]=(s[0][sl[i]]-'a'+1);
		for(int j=sl[i]+1;j<=sr[i];++j)hs[0][j]=(hs[0][j-1]*bs+(s[0][j]-'a'+1))%mod;
		hs[1][sl[i]]=(s[1][sl[i]]-'a'+1);
		for(int j=sl[i]+1;j<=sr[i];++j)hs[1][j]=(hs[1][j-1]*bs+(s[1][j]-'a'+1))%mod;
		B&=ck(s[0],sl[i],sr[i])&ck(s[1],sl[i],sr[i]);
	}
	L1=sr[n]*2;
	for(int i=1;i<=q;++i){
		tl[i]=tr[i-1]+1;
		scanf("%s%s",t[0]+tl[i],t[1]+tl[i]);
		tr[i]=tl[i]+(lent[i]=strlen(t[0]+tl[i]))-1;
		ht[0][tl[i]]=(t[0][tl[i]]-'a'+1);
		for(int j=tl[i]+1;j<=tr[i];++j)ht[0][j]=(ht[0][j-1]*bs+(t[0][j]-'a'+1))%mod;
		ht[1][tl[i]]=(t[1][tl[i]]-'a'+1);
		for(int j=tl[i]+1;j<=tr[i];++j)ht[1][j]=(ht[1][j-1]*bs+(t[1][j]-'a'+1))%mod;
		B&=ck(t[0],tl[i],tr[i])&ck(t[1],tl[i],tr[i]);
	}
	L2=tr[n]*2;
	if(n<=1000&&q<=1000&&L1<=2000&&L2<=2000){
		for(int i=1;i<=n;++i){
			++cnt[lens[i]][{gs(0,i,1,lens[i]),gs(1,i,1,lens[i])}];
		}
		for(int i=1;i<=q;++i){
			int res=0;
			for(int k=1;k<=lent[i];++k){
				for(int l=1,r=k;r<=lent[i];++l,++r){
					if(gt(0,i,1,l-1)!=gt(1,i,1,l-1)||gt(0,i,r+1,n)!=gt(1,i,r+1,n))continue;
					res+=cnt[k][{gt(0,i,l,r),gt(1,i,l,r)}];
				}
			}
			printf("%d\n",res);
		}
		return 0;
	}
	if(A&&B){
		for(int i=1;i<=n;++i){
			int pos0=0,pos1=0;
			for(int j=1;j<=lens[i];++j){
				if(s[0][sl[i]+j-1]=='b')pos0=j;
				if(s[1][sl[i]+j-1]=='b')pos1=j;
			}
			pb[i]=min(pos0,pos1)-1;
			sb[i]=lens[i]-max(pos0,pos1);
			gb[i]=pos1-pos0;
		}
		for(int i=1;i<=q;++i){
			int res=0;
			int pos0=0,pos1=0;
			for(int j=1;j<=lent[i];++j){
				if(t[0][tl[i]+j-1]=='b')pos0=j;
				if(t[1][tl[i]+j-1]=='b')pos1=j;
			}
			int np=min(pos0,pos1)-1,ns=lent[i]-max(pos0,pos1),ng=pos1-pos0;
			for(int j=1;j<=n;++j){
				if(ng==gb[j]&&np>=pb[j]&&ns>=sb[j])++res;
			}
			printf("%d\n",res);
		}
		return 0;
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

2
0
*/
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<M;++i)pw[i]=pw[i-1]*bs%mod;
	int T=1;
	while(T--){
		solve();
		if(T!=0)printf("\n");
	}
	fclose(stdin),fclose(stdout);
	return 0;
}
