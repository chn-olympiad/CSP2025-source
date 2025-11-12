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
const int N = 1e5+10;
static int ct[7],a[N][4],t[N],n,tot[4];
static int g[N],tp;
inline void solve(){
    readx(n);int ans = 0;
    tp = 0;
    FOR(j,1,6)ct[j] = 0;
    FOR(i,1,n){
        int mi = 1e9+10;
        FOR(j,1,3)readx(a[i][j]),mi = std::min(mi,a[i][j]);
        // printf("i:%d mi:%d\n",i,mi);
        FOR(j,1,3){
            if(mi==a[i][j])t[i] = j;
            a[i][j]-=mi;
        }
        ans+=mi;
        ans+=std::max(a[i][3],std::max(a[i][1],a[i][2]));
        if(a[i][1]&&a[i][2]){
            if(a[i][1]>a[i][2])++ct[t[i]=1];
            else ++ct[t[i]=2];
        }
        else if(a[i][1]&&a[i][3]){
            if(a[i][1]>a[i][3])++ct[t[i]=3];
            else ++ct[t[i]=4];
        }
        else if(a[i][2]&&a[i][3]){
            if(a[i][2]>a[i][3])++ct[t[i]=5];
            else ++ct[t[i]=6];
        }
        else if(a[i][1]||a[i][2]||a[i][3]){
            int p = 0;
            FOR(j,1,3)if(a[i][j])p = j;
            ++ct[t[i]=p];
        }
    }
    tot[1] = ct[3]+ct[1];
    tot[2] = ct[5]+ct[2];
    tot[3] = ct[4]+ct[6];
    // printf("%d %d %d\n",tot[1],tot[2],tot[3]);
    if(tot[1]>n/2){
        FOR(i,1,n){
            if(t[i]==1||t[i]==3)g[++tp] = std::max(a[i][2],a[i][3])-a[i][1];
        }
        std::sort(g+1,g+1+tp,[&](int x,int y){
            return x>y;
        });
        FOR(i,1,tot[1]-n/2)ans+=g[i];
        // ,printf("%d ",g[i]);putchar(10);
    }
    else if(tot[2]>n/2){
        FOR(i,1,n){
            if(t[i]==2||t[i]==5)g[++tp] = std::max(a[i][1],a[i][3])-a[i][2];
        }
        std::sort(g+1,g+1+tp,[&](int x,int y){
            return x>y;
        });
        FOR(i,1,tot[2]-n/2)ans+=g[i];
        // ,printf("%d ",g[i]);putchar(10);
    }
    else if(tot[3]>n/2){
        FOR(i,1,n){
            if(t[i]==6||t[i]==4)g[++tp] = std::max(a[i][1],a[i][2])-a[i][3];
        }
        std::sort(g+1,g+1+tp,[&](int x,int y){
            return x>y;
        });
        FOR(i,1,tot[3]-n/2)ans+=g[i];
        // ,printf("%d ",g[i]);putchar(10);
    }
    output(ans),putchar(10);
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;for(readx(t);t--;solve());
    return 0;
}
