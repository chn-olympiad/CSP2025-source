#include<bits/stdc++.h>
using namespace std;
namespace IO{
    template<typename T>inline void read(T&x){
        x=0;char c=getchar();bool f=0;while(!isdigit(c)) c=='-'?f=1:0,c=getchar();
        if(f) while(isdigit(c)) x=x*10-(c-'0'),c=getchar();
        else while(isdigit(c)) x=x*10+(c-'0'),c=getchar();
    }
    template<typename T>inline void write(T x){
        if(x==0){putchar('0');return ;}short st[50],top=0;
        if(x<0){putchar('-');while(x) st[++top]=-(x%10),x/=10;}
        else while(x) st[++top]=x%10,x/=10;while(top) putchar(st[top--]+'0');
    }
    inline void read(char&x){x=getchar();while(isspace(x)) x=getchar();}
    inline void write(char x){putchar(x);}
    inline void read(string&s){s.clear();char c;read(c);while(!isspace(c)&&~c) s+=c,c=getchar();}
    inline void write(string s){for(int i=0,len=s.size();i<len;i++) putchar(s[i]);}
    template<typename T>inline void write(T*x){while(*x) putchar(*x++);}
    template<typename T,typename...T2>inline void read(T&x,T2&...y){read(x),read(y...);}
    template<typename T,typename...T2>inline void write(const T x,const T2...y){write(x),putchar(' '),write(y...),sizeof...(y)==1?putchar('\n'):0;}
}using namespace IO;
const int maxn=100010,inf=10000000;
int n,us[maxn],g[5],ans;
struct node_for_set{
    int c,id;
    bool operator<(const node_for_set t)const{return c==t.c?id<t.id:c<t.c;}
};
multiset<node_for_set>s[10];
struct node{
    int z,id;
    bool operator<(const node t)const{
        return z>t.z;
    }
}a[maxn][10];
void solve(){
    while(g[1]>n/2){
        node_for_set h=*s[1].begin();
        s[1].erase(h);
        ans-=h.c,g[1]--;
    }
    while(g[2]>n/2){
        node_for_set h=*s[2].begin();
        s[2].erase(h);
        ans-=h.c,g[2]--;
    }
    while(g[3]>n/2){
        node_for_set h=*s[3].begin();
        s[3].erase(h);
        ans-=h.c,g[3]--;
    }
}
void tmain(){
    ans=0,s[1].clear(),s[2].clear(),s[3].clear();g[1]=g[2]=g[3]=0;
    read(n);
    for(int i=1;i<=n;i++){
        read(a[i][1].z,a[i][2].z,a[i][3].z),a[i][1].id=1,a[i][2].id=2,a[i][3].id=3,sort(a[i]+1,a[i]+4);
        g[a[i][1].id]++,s[a[i][1].id].insert({a[i][1].z-a[i][2].z,i});
        ans+=a[i][1].z;
    }
    solve();
    write(ans);
    write('\n');
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;read(T);
    while(T--) tmain();
    return 0;
}
