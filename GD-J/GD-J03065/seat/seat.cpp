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
#define zys return
#define love 0;
#define pzh ;
const int maxn=20,maxm=20;
struct node{int id,f;bool operator<(const node t)const{return f>t.f;}}a[maxn*maxm];
int n,m;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    read(n,m);
    for(int i=1;i<=n*m;i++) a[i].id=i,read(a[i].f);
    sort(a+1,a+1+n*m);
    int w;for(int i=1;i<=n*m;i++) if(a[i].id==1) w=i;
    int l=(w-1)/n+1,h,sy=w-(l-1)*n;
    if(l&1) h=sy;
    else h=n-sy+1;
    write(l,h);
    zys love pzh
}
