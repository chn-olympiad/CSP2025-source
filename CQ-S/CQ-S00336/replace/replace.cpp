#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(int i=a;i<=b;++i)
#define Rof(i,a,b) for(int i=a;i>=b;--i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=4e5+5,M=2.7e6+5,base=999983,Mod=998244353;
const int base2=233,Mod2=1e9+7;
bool SSS;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){f=(ch=='-'?-f:f);ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int n,Qu;
char s[M],t[M];
map<pair<pii,pii>,int>rt;
int cnt=1;
int ch[26][M]; 
vector<int>ed[M];
vector<pii>Q[M];
int f2[M],ans[N];
void dfs(int x){
	for(auto v:ed[x])f2[v]++;
	for(auto E:Q[x]){
		ans[E.se]+=f2[E.fi];
	}
	For(i,0,25){
		if(ch[i][x])dfs(ch[i][x]);
	}
	
	for(auto v:ed[x])f2[v]--;
}
bool TTT;
signed main(){
//	printf("%lld Mib\n",(int)(&TTT-&SSS)/1024/1024);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),Qu=read();
	For(T,1,n){
		scanf("%s",s+1);
		scanf("%s",t+1);
		int len=strlen(s+1);
		int L=1e9,R=0;
		For(j,1,len){
			if(s[j]!=t[j]){
				R=j;
				L=min(L,j);
			}
		}
		if(!R) continue;
		int hsh1=0,hsh2=0;
		For(i,L,R){
			hsh1=(hsh1*base+t[i]-'a'+1)%Mod;
			hsh2=(hsh2*base2+t[i]-'a'+1)%Mod2;
		}
		int hsh3=0,hsh4=0;
		For(i,L,R){
			hsh3=(hsh3*base+s[i]-'a'+1)%Mod;
			hsh4=(hsh4*base2+s[i]-'a'+1)%Mod2;
		}
		if(!rt.count({{hsh1,hsh2},{hsh3,hsh4}}))rt[{{hsh1,hsh2},{hsh3,hsh4}}]=++cnt;
		int p=rt[{{hsh1,hsh2},{hsh3,hsh4}}];
		int ss=p;
		Rof(i,L-1,1){
			int c=s[i]-'a';
			if(!ch[c][p]){
				ch[c][p]=++cnt;
			}p=ch[c][p];
		}
		int x=1;
		For(i,R+1,len){
			int c=s[i]-'a';
			if(!ch[c][x]){
				ch[c][x]=++cnt;
			}x=ch[c][x];
		}
		ed[p].push_back(x);
	}
	
	For(T,1,Qu){
		scanf("%s",s+1);
		scanf("%s",t+1);
		int len=strlen(s+1);
		int L=1e9,R=0;
		For(j,1,len){
			if(s[j]!=t[j]){
				R=j;
				L=min(L,j);
			}
		}
		if(!R){
			ans[T]=0;
			continue;
		}
		int hsh1=0,hsh2=0;
		For(i,L,R){
			hsh1=(hsh1*base+t[i]-'a'+1)%Mod;
			hsh2=(hsh2*base2+t[i]-'a'+1)%Mod2;
		}
		int hsh3=0,hsh4=0;
		For(i,L,R){
			hsh3=(hsh3*base+s[i]-'a'+1)%Mod;
			hsh4=(hsh4*base2+s[i]-'a'+1)%Mod2;
		}
		if(!rt.count({{hsh1,hsh2},{hsh3,hsh4}})){
			ans[T]=0;
			continue;
		}
		int p=rt[{{hsh1,hsh2},{hsh3,hsh4}}];
		Rof(i,L-1,1){
			int c=s[i]-'a';
			if(!ch[c][p]){
				break;
			}
			p=ch[c][p];
		}
		int x=1;
		Q[p].push_back({x,T});
		For(i,R+1,len){
			int c=s[i]-'a';
			if(!ch[c][x]){
				break;
			}x=ch[c][x];
			Q[p].push_back({x,T});
		}
	}
	for(auto v:rt){
		dfs(v.se);
	}
	For(i,1,Qu)printf("%lld\n",ans[i]);
	return 0;
}

