#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
const int N=2e5+5,L=5e6+5,mod=998244353,base1=673,base2=677;
int tot,v[27][27],w[27][27][27][27];
int n,m,Q,cnt,c[L]; char s[N],t[N];
unordered_map<int,int>son[L];
struct trie{
	int rt;
	trie(){}
	void set(){ rt=++cnt; }
	void ins(int x,int y){
		int m=strlen(s+1),p=rt;
		while(x>=1||y<=m){
			int z=w[x<1?26:s[x]-'a'][x<1?26:t[x]-'a']
				   [y>m?26:s[y]-'a'][y>m?26:t[y]-'a'];
			if(!son[p].count(z)) son[p][z]=++cnt;
			p=son[p][z],--x,++y;
		} ++c[p];
	}
	int ask(int x,int y){
		int m=strlen(s+1),p=rt,res=c[rt];
		while(x>=1||y<=m){
			int z=w[x<1?26:s[x]-'a'][x<1?26:t[x]-'a']
				   [y>m?26:s[y]-'a'][y>m?26:t[y]-'a'];
			if(!son[p].count(z)) return res;
			res+=c[p=son[p][z]],--x,++y;
		}
		return res;
	}
}tree[N];
map<pair<ll,ull>,int>mp;
void HitachiMako(){
	for(int i=0;i<=26;i++)
		for(int j=0;j<=26;j++)
			for(int k=0;k<=26;k++)
				for(int o=0;o<=26;o++)
					w[i][j][k][o]=++tot;
	tot=0;
	for(int i=0;i<=26;i++)
		for(int j=0;j<=26;j++)
			v[i][j]=++tot;
	tot=0;
	int num=0;
	scanf("%d%d",&n,&Q);
	while(n--){
		scanf("%s%s",s+1,t+1);
		m=strlen(s+1); int lcp=0,lcs=0;
		while(lcp<=m&&s[lcp]==t[lcp]) ++lcp;
		while(lcs<=m&&s[m-lcs]==t[m-lcs]) ++lcs;
		ll hs1=0; ull hs2=0;
		for(int i=lcp;i<=m-lcs;i++)
			hs1=(hs1*base1+v[s[i]-'a'][t[i]-'a'])%mod,
			hs2=hs2*base2+v[s[i]-'a'][t[i]-'a'];
		if(!mp.count(make_pair(hs1,hs2)))
			mp[make_pair(hs1,hs2)]=++num,tree[num].set();
		tree[mp[make_pair(hs1,hs2)]].ins(lcp-1,m-lcs+1);
	} 
	while(Q--){
		scanf("%s%s",s+1,t+1);
		m=strlen(s+1); int lcp=0,lcs=0;
		while(lcp<=m&&s[lcp]==t[lcp]) ++lcp;
		while(lcs<=m&&s[m-lcs]==t[m-lcs]) ++lcs;
		ll hs1=0; ull hs2=0;
		for(int i=lcp;i<=m-lcs;i++)
			hs1=(hs1*base1+v[s[i]-'a'][t[i]-'a'])%mod,
			hs2=hs2*base2+v[s[i]-'a'][t[i]-'a'];
		if(!mp.count(make_pair(hs1,hs2))) puts("0");
		else printf("%d\n",tree[mp[make_pair(hs1,hs2)]].ask(lcp-1,m-lcs+1));
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T=1;
	while(T--) HitachiMako();
	return 0;
} 
