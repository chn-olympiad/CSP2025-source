#include<bits/stdc++.h>
using namespace std;
namespace IO{
    template<typename T>inline void read(T&x){
        x=0;char c=getchar();bool f=0;
        while(!isdigit(c)) c=='-'?f=1:0,c=getchar();
        if(f) while(isdigit(c)) x=x*10-(c-'0'),c=getchar();
        else while(isdigit(c)) x=x*10+(c-'0'),c=getchar();
    }
    template<typename T>inline void write(T x){
        if(x==0){putchar('0');return ;}short st[50],top=0;
        if(x<0){putchar('-');while(x) st[++top]=-(x%10),x/=10;}
        else while(x) st[++top]=x%10,x/=10;
        while(top) putchar(st[top--]+'0');
    }
    inline void read(char&x){x=getchar();while(isspace(x)) x=getchar();}
    inline void write(char x){putchar(x);}
    inline void read(string&s){s.clear();char c;read(c);while(!isspace(c)&&~c) s+=c,c=getchar();}
    inline void write(string s){for(int i=0,len=s.size();i<len;i++) putchar(s[i]);}
    template<typename T>inline void write(T*x){while(*x) putchar(*x++);}
    template<typename T,typename...T2>inline void read(T&x,T2&...y){read(x),read(y...);}
    template<typename T,typename...T2>inline void write(const T x,const T2...y){write(x),putchar(' '),write(y...),sizeof...(y)==1?putchar('\n'):0;}
}using namespace IO;
#define yzx return
#define love 0;
#define lxy ;
const int maxn=5010,maxval=5010,mod=998244353;
int f[maxn][maxval*2],n,a[maxn],ans,g[maxn][maxval*2];
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    read(n);for(int i=1;i<=n;i++) read(a[i]);sort(a+1,a+1+n);
    g[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=a[n]*2+1;j++) g[i][j]=g[i-1][j];
        for(int j=0;j<=a[n]*2+1;j++) g[i][min(j+a[i],a[n]*2+1)]=(g[i][min(j+a[i],a[n]*2+1)]+g[i-1][j])%mod;
        for(int j=0;j<=a[n]*2+1;j++){
            f[i][min(j+a[i],a[n]*2+1)]=(f[i][min(j+a[i],a[n]*2+1)]+g[i-1][j])%mod;
        }
    }
    for(int i=1;i<=n;i++) for(int j=a[i]*2+1;j<=a[n]*2+1;j++) ans=(ans+f[i][j])%mod;
    write(ans);
    yzx love lxy;
}
/*
5
1 2 3 4 5
*/
