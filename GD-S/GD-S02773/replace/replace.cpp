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
#define uLL unsigned long long
const int maxn=2000010,maxlen=5000010;
const uLL jz=223,jz2=61,jz3=998244353;
uLL mi[maxlen],mi2[maxlen],mi3[maxlen];
int n,q,cnt,g[maxn];
string bi[maxn][2];
class HASH{
private:
    uLL h[maxlen],h2[maxlen],h3[maxlen];
public:
    void build(string s){
        for(int i=0,len=s.size();i<len;i++) h[i+1]=h[i]*jz+s[i]-'a'+1;
        for(int i=0,len=s.size();i<len;i++) h2[i+1]=h2[i]*jz2+s[i]-'a'+1;
        for(int i=0,len=s.size();i<len;i++) h3[i+1]=h3[i]*jz3+s[i]-'a'+1;
    }
    pair<uLL,pair<uLL,uLL>> query(int l,int r){
        return {h[r]-h[l-1]*mi[r-l+1],{h2[r]-h2[l-1]*mi2[r-l+1],h3[r]-h3[l-1]*mi3[r-l+1]}};
    }
}h1,h2;
map<pair<uLL,pair<uLL,uLL>>,int>mp,mp2,mp3;
vector<int>vt[maxn*5];
bool flag[maxn];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    mi[0]=1;
    mi2[0]=1;
    mi3[0]=1;
    for(int i=1;i<=5000000;i++) mi[i]=mi[i-1]*jz;
    for(int i=1;i<=5000000;i++) mi2[i]=mi2[i-1]*jz2;
    for(int i=1;i<=5000000;i++) mi3[i]=mi3[i-1]*jz3;
    read(n,q);
    for(int i=1;i<=n;i++){
        string s1,s2;read(s1,s2);
        bi[i][0]=s1,bi[i][1]=s2;
        int be=0,en=0;
        for(int j=0;j<s1.size();j++){
            if(s1[j]!=s2[j]){
                if(be==0) be=j+1;
                en=j+1;
            }
        }
        if(be==0) continue;
        h1.build(s1),h2.build(s2);
        for(int w=1;w<=be;w++){
            auto z=h1.query(w,en);
            if(mp[z]==0) mp[z]=++cnt;
            vt[mp[z]].push_back(i);
        }
        for(int w=en;w<=s1.size();w++){
            auto z=h1.query(be,w);
            if(mp2[z]==0) mp2[z]=++cnt;
            vt[mp2[z]].push_back(i);
        }
        auto z=h2.query(be,en);
        if(mp3[z]==0) mp3[z]=++cnt;
        vt[mp3[z]].push_back(i);
    }
    for(int i=1;i<=q;i++){
        string s1,s2;read(s1,s2);
        if(s1.size()!=s2.size()){
            write("0\n");
            continue;
        }
        int be=0,en=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                if(be==0) be=i+1;
                en=i+1;
            }
        }
        h1.build(s1),h2.build(s2);
        auto z=h1.query(1,en);
        auto z2=h1.query(be,s1.size());
        auto z3=h2.query(be,en);
        if(mp[z]==0||mp2[z2]==0||mp3[z3]==0){
            write("0\n");
            continue;
        }
        int x=mp[z],x1=mp2[z2],x2=mp3[z3];
        for(int w:vt[x]) g[w]++;
        for(int w:vt[x1]) g[w]++;
        int ans=0;
        // if(i==101) write(s1,s2);
        for(int w:vt[x2]) if(g[w]==2){
            ans++;
        }
        for(int w:vt[x]) g[w]=0;
        for(int w:vt[x1]) g[w]=0;
        write(ans);write('\n');
    }
    return 0;
}
