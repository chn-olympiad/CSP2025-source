#include<bits/stdc++.h>
#define ep emplace
#define eb emplace_back
#define fr(i,l,r) for(int i(l),_##i(r);i<=_##i;i++)
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
template<class T>inline T rd(T&x){
    bool f=1;T a=0;char c=getchar_unlocked();
    for(;c<'0'||c>'9';c=getchar_unlocked())f&=c!='-';
    for(;c>='0'&&c<='9';c=getchar_unlocked())a=c-'0'+a*10;
    return x=f?a:-a;
}template<class T,class...U>inline void rd(T&x,U&...y){rd(x),rd(y...);}
using namespace std;using ll=long long;using ull=unsigned long long;
const int N=2e5+3,M=5e6+3,B=233,P=998244853;
int n,q,tot;ll ans[N];
char *sa[N],*sb[N],*ta[N],*tb[N],a[M],b[M];

namespace subB {
    basic_string<array<int,2>>vec[M+M];
    basic_string<array<int,3>>qry[M+M];
    int c[M],V=0;
    inline void add(int k,int x){for(++k;k<=V;k+=k&-k)c[k]+=x;}
    inline int ask(int k){int r=0;for(++k;k;k&=k-1)r+=c[k];return r;}
    int main(){
        int mn=1e9,mx=0;
        fr(i,1,n){
            int len=strlen(sa[i]+1),k1,k2;
            V=max(V,len+1);
            fr(j,1,len){
                if(sa[i][j]=='b')k1=j;
                if(sb[i][j]=='b')k2=j;
            }vec[k2-k1+M]+={k1-1,len-k1};
        }
        fr(i,1,q){
            int len=strlen(ta[i]+1),k1,k2;
            fr(j,1,len){
                if(ta[i][j]=='b')k1=j;
                if(tb[i][j]=='b')k2=j;
            }qry[k2-k1+M]+={k1-1,len-k1,i};
            mn=min(mn,k2-k1+M),mx=max(mx,k2-k1+M);
        }
        fr(i,mn,mx)if(qry[i].size()){
            sort(begin(vec[i]),end(vec[i])),sort(begin(qry[i]),end(qry[i]));
            int j=-1,sz=vec[i].size();
            for(auto[L,R,id]:qry[i]){
                while(j<sz-1&&vec[i][j+1][0]<=L)add(vec[i][++j][1],1);
                ans[id]+=ask(R);
            }fr(k,0,j)add(vec[i][k][1],-1);
        }
        fr(i,1,q)cout<<ans[i]<<'\n';
        return 0;
    }
}

struct HASH {
    int x;ull y;
    bool operator<(const HASH&b)const{return x^b.x?x<b.x:y<b.y;}
    bool operator==(const HASH&b)const{return x==b.x&&y==b.y;}
}pw[M];

struct node {
    HASH x,y;int id;
    bool operator<(const node&b)const{return x==b.x?y<b.y:x<b.x;}
    bool operator==(const node&b)const{return x==b.x&&y==b.y;}
}s[N],t[M];

inline HASH hsh(char*s,int len){
    int x=0;ull y=0;
    fr(i,1,len)x=(1ll*x*B%P+s[i])%P,y=y*B+s[i];
    return(HASH){x,y};
}

int main(){
    file(replace);
    rd(n,q),pw[0]={1,1};
    fr(i,1,5000000)pw[i].x=1ll*pw[i-1].x*B%P,pw[i].y=pw[i-1].y*B;
    bool flB=1;
    fr(i,1,n){
        scanf("%s%s",a+1,b+1);
        int len=strlen(a+1),ca=0,cb=0;
        sa[i]=new char[len+2],sb[i]=new char[len+2];
        fr(j,0,len+1){
            sa[i][j]=a[j],sb[i][j]=b[j];
            if(j&&j<=len)flB&=(a[j]=='a'||a[j]=='b')&&(b[j]=='a'||b[j]=='b'),ca+=a[j]=='b',cb+=b[j]=='b';
        }flB&=ca==1&&cb==1;
    }
    fr(i,1,q){
        scanf("%s%s",a+1,b+1);
        int len=strlen(a+1),ca=0,cb=0;
        ta[i]=new char[len+2],tb[i]=new char[len+2];
        fr(j,0,len+1){
            ta[i][j]=a[j],tb[i][j]=b[j];
            if(j&&j<=len)flB&=(a[j]=='a'||a[j]=='b')&&(b[j]=='a'||b[j]=='b'),ca+=a[j]=='b',cb+=b[j]=='b';
        }flB&=ca==1&&cb==1;
    }

    if(flB)return subB::main();

    fr(i,1,n){
        int len=strlen(sa[i]+1);
        fr(j,0,len+1)a[j]=sa[i][j],b[j]=sb[i][j];
        s[i]={hsh(a,len),hsh(b,len),0};
    }sort(s+1,s+n+1);
    fr(i,1,q){
        // scanf("%s%s",a+1,b+1);
        // int len=strlen(a+1),l=0,r=len+1;
        int len=strlen(ta[i]+1),l=0,r=len+1;
        fr(j,0,len+1)a[j]=ta[i][j],b[j]=tb[i][j];
        while(a[l+1]==b[l+1])l++;
        while(a[r-1]==b[r-1])r--;
        // cout<<i<<' '<<l<<' '<<r<<" !\n";
        // fr(i,1,len)putchar(a[i]);
        // puts("");
        // fr(i,1,len)putchar(b[i]);
        HASH ha=hsh(a+l,r-l-1),hb=hsh(b+l,r-l-1);
        t[++tot]={ha,hb,i};
        for(int L=l;L;L--){
            HASH na=ha,nb=hb;
            na.x=(na.x+1ll*pw[r-L-1].x*a[L]%P)%P,na.y+=pw[r-L-1].y*a[L];
            nb.x=(nb.x+1ll*pw[r-L-1].x*b[L]%P)%P,nb.y+=pw[r-L-1].y*b[L];
            ha=na,hb=nb,t[++tot]={na,nb,i};
            fr(R,r,len)
                na.x=(1ll*na.x*B%P+a[R])%P,na.y=na.y*B+a[R],
                nb.x=(1ll*nb.x*B%P+b[R])%P,nb.y=nb.y*B+b[R],
                t[++tot]={na,nb,i};
        }
    }sort(t+1,t+tot+1);

    // fr(i,1,n)cout<<s[i].x.x<<' '<<s[i].x.y<<"  "<<s[i].y.x<<' '<<s[i].y.y<<'\n';
    // puts("---");
    // fr(i,1,tot)cout<<t[i].x.x<<' '<<t[i].x.y<<"  "<<t[i].y.x<<' '<<t[i].y.y<<' '<<t[i].id<<'\n';

    int j=0;fr(i,1,tot){
        while(j<n&&s[j+1]<t[i])j++;
        int jj=j;
        while(j<n&&s[j+1]==t[i])j++;
        auto tt=t[i];
        while(i<=tot&&t[i]==tt)ans[t[i++].id]+=j-jj;
        i--;
    }
    fr(i,1,q)cout<<ans[i]<<'\n';
    return 0;
}