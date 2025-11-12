#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool st;
const int inf=1e9+8;
const int Maxn=2e5+6,Maxm=5e6+7;
int n,Q;
string s[Maxn][2];
string b[Maxn],e[Maxn];
int ls[Maxn];

map<int,int>trie[Maxm];
int tot;
int val[Maxm],sz[Maxm];
map<string,map<string,int> >mp;
bool ed;

inline int trans(int u,int v){
	return u*27+v;
}
inline void Insert(int rt,string bk,string ek){
	reverse(bk.begin(),bk.end());
	int p=rt;
	int l=max(bk.size(),ek.size());
	int mn=min(bk.size(),ek.size());
	for(int i=0;i<l;i++){
		int u,v;
		if(i>=mn){
			if(bk.size()>ek.size()) u=bk[i]-'a',v=26;
			else u=26,v=ek[i]-'a';
		}
		else u=bk[i]-'a',v=ek[i]-'a';
		int ok=trans(u,v);
		if(!trie[p][ok]) trie[p][ok]=++tot;
		p=trie[p][ok]; 
	}
	val[p]++;
}

string bk,ek;
int dfs(int p,int i){
	if(!p) return 0;
	int l=max(bk.size(),ek.size());
	int mn=min(bk.size(),ek.size());
	int u,v;
	if(i>=mn){
		if(bk.size()>ek.size()) u=bk[i]-'a',v=26;
		else u=26,v=ek[i]-'a';
	}
	else u=bk[i]-'a',v=ek[i]-'a';
	int ok=trans(u,v);
	int ret=dfs(trie[p][ok],i+1);
	if(trie[p][trans(u,26)] and v!=26) ret+=dfs(trie[p][trans(u,26)],i+1);
	if(trie[p][trans(26,v)] and u!=26) ret+=dfs(trie[p][trans(26,v)],i+1);
	return ret+val[p];
}
inline int query(int rt,string bk,string ek){
	int p=rt,ret=val[rt];
	int l=max(bk.size(),ek.size());
	int mn=min(bk.size(),ek.size());
	for(int i=0;i<l;i++){
		int u,v;
		if(i>=mn){
			if(bk.size()>ek.size()) u=bk[i]-'a',v=26;
			else u=26,v=ek[i]-'a';
		}
		else u=bk[i]-'a',v=bk[i]-'a';
		int ok=trans(u,v);
		p=trie[p][ok]; if(!p) break;
		ret+=val[p];
	}
	return ret;
}

int main(){
	cerr<<(&ed-&st)*1./1024/1024<<"\n";
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		ls[i]=s[i][0].size();
		int L=-1,R=ls[i];
		for(int j=0;j<ls[i];j++){
			if(s[i][0][j]==s[i][1][j]) b[i]+=s[i][0][j],L=j;
			else break;
		}
		for(int j=ls[i]-1;~j;j--){
			if(s[i][0][j]==s[i][1][j]) e[i]+=s[i][0][j],R=j;
			else break;
		}
		reverse(e[i].begin(),e[i].end());
		string ns0,ns1;
		for(int j=L+1;j<R;j++) 
			ns0+=s[i][0][j],
			ns1+=s[i][1][j];
		
		if(!mp[ns0][ns1]) mp[ns0][ns1]=++tot;
		Insert(mp[ns0][ns1],b[i],e[i]);
	}
	
	int id=0;
	while(Q--){
		id++;
		string t0,t1;
		cin>>t0>>t1;
		bk.clear(),ek.clear();
		int len=t0.size();
		int l=len-1,r=0;
		for(int j=0;j<len;j++){
			if(t0[j]!=t1[j])
				l=min(l,j),r=max(r,j);
		}
		string ns0,ns1;
		for(int j=l;j<=r;j++)
			ns0+=t0[j],
			ns1+=t1[j];
		if(!mp[ns0][ns1]){
			puts("0");
			continue;
		}
		int rt=mp[ns0][ns1];
		for(int i=0;i<l;i++) bk+=t0[i];
		for(int i=r+1;i<len;i++) ek+=t0[i];
		
		reverse(bk.begin(),bk.end());
		
		printf("%d\n",dfs(rt,0));		
	}

	return 0;
}
/*
应该是数据结构+字符串

暴力有 50pts 

l<=L and r>=R
s0i=t0(l,r) ,
s1i=t1(l,r) .

看起来正解很简单。
就是字典树。。。不过是改版的 
 
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
 
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
