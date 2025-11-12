#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _ll __int128
#define Pii pair<int,int>
#define ull unsigned long long
template<typename T>inline void chkmin(T &x,T y){(x>y)&&(x=y);}
template<typename T>inline void chkmax(T &x,T y){(x<y)&&(x=y);}
namespace IO{
	bool Isdigit(char c){return c>='0'&&c<='9';}
	template<typename T>inline void read(T &x){
		x=0;char c=getchar();bool f=1;
		while(!Isdigit(c)){if(c=='-')f=0;c=getchar();}
		while(Isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
		x=f?x:-x;
	}
	template<typename T,typename ...Args>
	inline void read(T &x,Args &...args){read(x),read(args...);}
	int STK[110],TOP;
	inline void Write(int x){if(x==0)return putchar('0'),void();if(x<0)putchar('-'),x=-x;TOP=0;while(x)STK[++TOP]=x%10,x/=10;while(TOP)putchar(STK[TOP--]^48);}
	inline void Write(ll x){if(x==0)return putchar('0'),void();if(x<0)putchar('-'),x=-x;TOP=0;while(x)STK[++TOP]=x%10,x/=10;while(TOP)putchar(STK[TOP--]^48);}
	inline void Write(ull x){if(x==0)return putchar('0'),void();if(x<0)putchar('-'),x=-x;TOP=0;while(x)STK[++TOP]=x%10,x/=10;while(TOP)putchar(STK[TOP--]^48);}
	inline void Write(_ll x){if(x==0)return putchar('0'),void();if(x<0)putchar('-'),x=-x;TOP=0;while(x)STK[++TOP]=x%10,x/=10;while(TOP)putchar(STK[TOP--]^48);}
	inline void Write(unsigned x){if(x==0)return putchar('0'),void();if(x<0)putchar('-'),x=-x;TOP=0;while(x)STK[++TOP]=x%10,x/=10;while(TOP)putchar(STK[TOP--]^48);}
	inline void Write(char c){putchar(c);}
	inline void Write(const char *c){while(*c)putchar(*c++);}
	template<typename T,typename ...Args>
	inline void Write(T x,Args ...args){Write(x),Write(args...);}
}
using namespace IO;
const int N=2e5+10,M=5e6+10;
const int Bas1=13333,Bas2=114191,Mod1=998244353,Mod2=1e9+7;
char S[M],T[M];
map<Pii,int> Map;
int n,Q,cnt,tot,Rt[N],Tr[M][26],F[M],Fail[M];
void Insert(int Len,Pii V){
	if(!Map.count(V))
		Map[V]=++tot,++cnt,Rt[tot]=++cnt;
	int u=Rt[Map[V]];
	for(int i=1;i<=Len;i++){
		int v=S[i]-'a';
		if(!Tr[u][v])
			Tr[u][v]=++cnt;
		u=Tr[u][v];
	}
	F[u]++;
}
queue<int> q;
void Build(int Id){
	int St=Rt[Id];
	for(int i=0;i<26;i++)
		Tr[St-1][i]=St;
	Fail[St]=St-1,q.push(St);
	while(q.size()){
		int u=q.front();q.pop();
		F[u]+=F[Fail[u]];
		for(int i=0;i<26;i++)
			if(!Tr[u][i])
				Tr[u][i]=Tr[Fail[u]][i];
			else{
				q.push(Tr[u][i]);
				Fail[Tr[u][i]]=Tr[Fail[u]][i];
			}
	}
}
ll Query(int Id,int l,int r){
	int u=Rt[Id];
	ll Res=0;
	for(int i=l;i<=r;i++)
		Res+=F[u=Tr[u][S[i]-'a']];
	return Res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",S+1,T+1);
		int l=1,r=strlen(S+1);
		while(S[l]==T[l])++l;
		while(S[r]==T[r])--r;
		int Num_1=0,Num_2=0;
		for(int j=l;j<=r;j++){
			Num_1=(1LL*Num_1*Bas1+S[j]-'a')%Mod1;
			Num_2=(1LL*Num_2*Bas2+T[j]-'a')%Mod2;
		}
		Insert(strlen(S+1),make_pair(Num_1,Num_2));
	}
	for(int i=1;i<=tot;i++)Build(i);
	while(Q--){
		scanf("%s%s",S+1,T+1);
		if(strlen(S+1)!=strlen(T+1)){
			Write("0\n");
			continue;
		}
		int l=1,r=strlen(S+1),Len=strlen(S+1);
		while(S[l]==T[l])++l;
		while(S[r]==T[r])--r;
		int Num_1=0,Num_2=0;
		for(int j=l;j<=r;j++){
			Num_1=(1LL*Num_1*Bas1+S[j]-'a')%Mod1;
			Num_2=(1LL*Num_2*Bas2+T[j]-'a')%Mod2;
		}
		Pii V=make_pair(Num_1,Num_2);
		if(!Map.count(V))Write("0\n");
		else{
			int x=Map[V];
			Write(Query(x,1,Len)-Query(x,1,r-1)-Query(x,l+1,Len),'\n');
		}
	}
}