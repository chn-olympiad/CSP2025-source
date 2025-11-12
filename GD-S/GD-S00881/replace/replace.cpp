#include <bits/stdc++.h>
#define ll long long
#define pii array<int,2>
using namespace std;
ll read(){
	ll s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+(ch-'0');
		ch=getchar();
	}
	return s*f;
}
const int mod1=968736437,mod2=1052096939,base1=199,base2=211;
pii hs(char *s,int l,int r){
	int res1=0,res2=0;
	for(int i=l;i<=r;i++)
		res1=(1ll*res1*base1+(s[i]-'a'+1))%mod1,
		res2=(1ll*res2*base2+(s[i]-'a'+1))%mod2;
	return {res1,res2};
}
map<pair<pii,pii>,int>mp;
int mcnt;
int tr[5000010][26],fail[5000010],cnt;
vector<int>s[5000010];
vector<int>e[5000010];
vector<pii>qu[5000010];
int rt[200010],ans[200010];
int add(int p,char *s){
	int len=strlen(s);
	for(int i=0,x;i<len;i++){
		x=s[i]-'a';
		if(!tr[p][x]) tr[p][x]=++cnt;
		p=tr[p][x];
	}
	return p;
}
void addq(int p,char *s,int id,int pos){
	if(!p) return;
	int len=strlen(s);
	for(int i=0;i<len;i++){
		p=tr[p][s[i]-'a'];
		if(i>=pos) qu[p].push_back({i-pos,id});
	}
}
queue<int>q;
void build(int s){
	for(int i=0;i<26;i++) tr[0][i]=s;
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		e[fail[u]].push_back(u);
		for(int i=0;i<26;i++){
			if(tr[u][i]) fail[tr[u][i]]=tr[fail[u]][i],q.push(tr[u][i]);
			else tr[u][i]=tr[fail[u]][i];
		}
	}
}
int n,Q,val[5000010];
char sl[5000010],sr[5000010];
void solve(int u){
	// printf("vis %d\n",u);
	for(int v:s[u]) val[v]++;
	for(pii v:qu[u]) ans[v[1]]+=val[v[0]];
	for(int v:e[u]) solve(v);
	for(int v:s[u]) val[v]--;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	// clock_t st=clock();
	n=read(),Q=read();
	for(int i=1,len,pos,l,r,hpos;i<=n;i++){
		static pii hl,hr;
		scanf("%s%s",sl,sr);
		len=strlen(sl);
		l=0,r=len-1;
		while(l<len&&sl[l]==sr[l]) l++;
		if(l==len) continue;
		while(r>=0&&sl[r]==sr[r]) r--;
		hl=hs(sl,l,r),hr=hs(sr,l,r);
		// printf("%d %d\n",l,r);
		// printf("%d %d %d %d\n",hl[0],hl[1],hr[0],hr[1]);
		if(!mp[make_pair(hl,hr)]) mp[make_pair(hl,hr)]=++mcnt;
		hpos=mp[make_pair(hl,hr)];
		if(!rt[hpos]) rt[hpos]=++cnt;
		pos=add(rt[hpos],sl);
		s[pos].push_back(len-r-1);
	}
	for(int i=1;i<=mcnt;i++) build(rt[i]);
	// puts("into query");
	for(int i=1,len,l,r,hpos;i<=Q;i++){
		static pii hl,hr;
		scanf("%s%s",sl,sr);
		len=strlen(sl);
		l=0,r=len-1;
		while(l<len&&sl[l]==sr[l]) l++;
		while(r>=0&&sl[r]==sr[r]) r--;
		hl=hs(sl,l,r),hr=hs(sr,l,r);
		// printf("%d %d\n",l,r);
		// printf("%d %d %d %d\n",hl[0],hl[1],hr[0],hr[1]);
		hpos=mp[make_pair(hl,hr)];
		addq(rt[hpos],sl,i,r);
	}
	solve(0);
	for(int i=1;i<=Q;i++)
		printf("%d\n",ans[i]);
	// fprintf(stderr,"%.4lf\n",(clock()-st)*1.0/CLOCKS_PER_SEC);
	return 0;
}
//g++ replace.cpp -o replace -std=c++14 -O2 -Wall -Wextra -fno-ms-extensions