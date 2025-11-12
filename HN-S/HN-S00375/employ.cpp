#include<bits/stdc++.h>
using namespace std;
#define int long long
#define All(v) v.begin(),v.end()
#define lowbit(x) (x&-x)
using ull=unsigned long long;
using pii=pair<int,int>;
const int N=505,mod=998244353;
int n,m,a[N];
char s[N];
int f[1<<19][19];
inline int read(){
    register int x(0),t(0);
    static char ch=getchar();
    while(!isdigit(ch)){t|=(ch=='-');ch=getchar();}
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return t?-x:x;
}
inline void Add(int &x,const int y){x+=y,x>=mod?x-=mod:1;}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    f[0][0]=1;
    for(int S=0;S<(1<<n)-1;S++){
        int now=__builtin_popcount(S);
        for(int j=0;j<=n;j++){
            if(!f[S][j]) continue;
            for(int i=1;i<=n;i++){
                if(S>>i-1&1) continue;
                Add(f[S|(1<<i-1)][j+(a[i]>now-j&&s[now+1]=='1')],f[S][j]);
            }
        }
    }
    int res=0;
    for(int i=m;i<=n;i++) Add(res,f[(1<<n)-1][i]);
    cout<<res;
    return 0;
}