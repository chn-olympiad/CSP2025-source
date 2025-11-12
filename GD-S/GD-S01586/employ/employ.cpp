#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _ll __int128
#define ull unsigned long long
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
const int N=510;
char S[N];
int n,m,c[N],Cnt[N],P[N];
bool Check_1(){int Num=0;for(int i=1;i<=n;i++)Num+=S[i]=='1';return Num==n;}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,S+1);
	// if(Check_1()){
		// int Res=1;
		// for(int i=2;i<=n;i++)
			// Res=1LL*Res*i%Mod;
		// Write(Res,'\n');
	// }
	for(int i=1;i<=n;i++)
		read(c[i]);
	for(int i=1;i<=n;i++)P[i]=i;
	do{
		int Num=0;
		for(int i=1;i<=n;i++)
			Num+=(S[i]=='0'||c[P[i]]<=Num);
		Cnt[Num]++;
	}while(next_permutation(P+1,P+n+1));
	for(int i=1;i<=n;i++)Cnt[i]+=Cnt[i-1];
	Write(Cnt[n-m],'\n');
}