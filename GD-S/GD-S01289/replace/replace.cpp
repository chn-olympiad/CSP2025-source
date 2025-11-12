#include<bits/stdc++.h>
#define ll long long
#define oF(l,r,i) for(int i=l;i<=r;i++)
#define of(l,r) for(int i=l;i<=r;i++)
#define tF(n,i) oF(1,n,i)
#define tf(n) oF(1,n,i)
#define nF(i) oF(1,n,i)
#define nf() oF(1,n,i)
#define pb emplace_back
#define pint pair<int,int>
#define mp make_pair
#define f first
#define s second
#define file(x) (freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),0)
#define check(x) file(x);ifstream Ans(#x".ans");
using namespace std;
ll read(){
	ll x=0;
	char c=getchar();
	while(c<48)c=getchar();
	while(c>47)x=(x<<3)+(x<<1)+(c&15),c=getchar();
	return x;
}
void write(ll x){
	if(x>9)write(x/10);
	putchar(x%10|48);
}
char gtch(){
	char c=getchar();
	while(c<33)c=getchar();
	return c;
}
string gts(){
	string s="";
	char c=gtch();
	while(c>32)s+=c,c=getchar();
	return s;
}
int xxx=file(replace);
int n=read(),m=read();
int NXT[3000005][27],V[3000005],id,fail[3000005];
int s[6000005][27],val[6000005],cnt;
string s1,s2,spre,ssuf,sm1,sm2;
int find(const string&str){
	int p=0;
	for(char c:str){
		int x=c&31;
		if(!s[p][x])s[p][x]=++cnt;
		p=s[p][x];
	}
	if(!val[p]){
		val[p]=++id;
	}
	return val[p];
}
int finde(const string&str){
	int p=0;
	for(char c:str){
		int x=c&31;
		if(!s[p][x])return 0;
		p=s[p][x];
	}
	return val[p];
}
void insert(int p,const string&str){
	for(char c:str){
		int x=c&31;
		if(!NXT[p][x])NXT[p][x]=++id;
		p=NXT[p][x];
	}
	V[p]++;
}
queue<int>q;
void pre(int RT){
	for(int i=0;i<=26;i++)if(NXT[RT][i])fail[NXT[RT][i]]=RT,q.push(NXT[RT][i]);else NXT[RT][i]=RT;
	while(q.size()){
		int x=q.front();q.pop();
		V[x]+=V[fail[x]];
		for(int i=0;i<=26;i++){
			if(!NXT[x][i])NXT[x][i]=NXT[fail[x]][i];
			else fail[NXT[x][i]]=NXT[fail[x]][i],q.push(NXT[x][i]);
		}
	}
}
int sum(int p,const string&s){
	int ans=0;
	for(char c:s){
		ans+=V[p=NXT[p][c&31]];
	}
	return ans;
}
signed main(){
	nf(){
		s1=gts();s2=gts();
		if(s1==s2)continue;
		int L=s1.size(),l=0,r=L-1;
		while(s1[l]==s2[l])l++;
		while(s1[r]==s2[r])r--;
		spre=s1.substr(0,l+1);
		ssuf=s1.substr(r+1);
		sm1=s1.substr(l,r-l+1);
		sm2=s2.substr(l,r-l+1);
		insert(find(sm1+'`'+sm2),spre+'`'+ssuf);		
	}
	tf(cnt)if(val[i])pre(val[i]);
	tf(m){
		s1=gts();s2=gts();
		if(s1.length()!=s2.length()){
			puts("0");continue;
		}
		int L=s1.size(),l=0,r=L-1;
		while(s1[l]==s2[l])l++;
		while(s1[r]==s2[r])r--;
		spre=s1.substr(0,l+1);
		ssuf=s1.substr(r+1);
		sm1=s1.substr(l,r-l+1);
		sm2=s2.substr(l,r-l+1);
		int v=finde(sm1+'`'+sm2);
		write(v?sum(v,spre+'`'+ssuf):0);putchar(10);	
	}
}
