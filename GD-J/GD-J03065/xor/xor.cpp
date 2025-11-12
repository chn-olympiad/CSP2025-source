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
#define hme return
#define love 0;
#define lhy ;
const int maxn=500010,maxk=1100000;
int f[maxn],a[maxn],n,k,sum[maxn],g[maxk],ans;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    read(n,k);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
    memset(g,-1,sizeof(g));g[0]=0;
    for(int i=1;i<=n;i++){
        f[i]=g[k^sum[i]]+1;
        g[sum[i]]=max(g[sum[i]],f[i]);ans=max(ans,f[i]);
        g[sum[i]]=max(g[sum[i]],g[sum[i-1]]);
    }
    write(ans);
    hme love lhy
}
