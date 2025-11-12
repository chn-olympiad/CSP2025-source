#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a);i <= (b);++i)
#define REP(i,a,b) for(int i = (a);i >= (b);--i)
#define GO(x) for(int i = h[x],y = e[i];i;y = e[i=ne[i]])
#define ll long long
static char stkk[200];
template<typename T>inline void output(T x){
    if(!x)return putchar('0'),void();
    if(x<0)x = ~x+1,putchar('-');
    int top = 0;
    for(;x;stkk[++top]=x%10^48,x/=10);
    for(;top;putchar(stkk[top--]));
}
template<typename T>inline void readx(T& x){
    x = 0;int y = 1;char c = getchar();
    for(;c<48||c>58;c = getchar())if(c=='-')y = -1;
    for(;c>=48&&c<=58;c = getchar())x = (x<<1)+(x<<3)+(c^48);
    x *= y;
}
const int N = 2e3+10;
static char s1[N],s2[N],q1[N],q2[N],n,m,lens[N],lenq[N];
inline bool check(char *s1,char * s2,int p,int l1,int l2){
    if(p+l1-1>l2)return 0;
    FOR(i,p,p+l1-1)if(s1[i]!=s2[i])return 0;
    return 1;
}
inline bool ok(int id,int p){
    return check(s1[id],q1[p],lens[id],lenq[p])&&check(s2[id],q2[p],lens[id],lenq[p]);
}

signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    readx(n),readx(m);
    FOR(i,1,n){
        scanf(" %s",s1+1);
        scanf(" %s",s2+1);
        lens[i] = std::strlen(s1+1);
    }
    FOR(i,1,m){
        scanf(" %s",q1+1);
        scanf(" %s",q2+1);
        lenq[i] = std::strlen(s1+1);
    }
    FOR(i,1,m){
        int ans = 0;
        FOR(j,1,lenq[i]){
            FOR(k,1,n)if(ok(i,j))++ans;
        }
        output(ans),putchar(10);
    }
    return 0;
}
