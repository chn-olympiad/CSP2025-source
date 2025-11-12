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
const int N=1e5+10;
vector<int> B[3];
int T,n,Res,Cnt[3],P[N][3],a[N][3];
void Solve(){
	read(n),Res=0;
	for(int i:{0,1,2})
		Cnt[i]=0,B[i].clear();
	for(int i=1;i<=n;i++){
		for(int j:{0,1,2}){
			P[i][j]=j;
			read(a[i][j]);
		}
		sort(P[i],P[i]+3,[&](int x,int y){return a[i][x]>a[i][y];});
		Cnt[P[i][0]]++;
		Res+=a[i][P[i][0]];
		B[P[i][0]].emplace_back(a[i][P[i][0]]-a[i][P[i][1]]);
	}
	if(max({Cnt[0],Cnt[1],Cnt[2]})<=n/2)
		return Write(Res,'\n');
	for(int i:{0,1,2})P[0][i]=i;
	sort(P[0],P[0]+3,[&](int x,int y){return Cnt[x]>Cnt[y];});
	int Num=P[0][0];
	sort(B[Num].begin(),B[Num].end());
	for(int i=0;i<Cnt[Num]-n/2;i++)
		Res-=B[Num][i];
	Write(Res,'\n');
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	while(T--)
		Solve();
}