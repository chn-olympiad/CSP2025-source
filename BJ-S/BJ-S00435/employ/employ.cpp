#include<bits/stdc++.h>
#define rep(i,s,t) for(int i=s;i<=t;++i)
#define per(i,t,s) for(int i=t;i>=s;--i)
using namespace std;
template<typename T>
inline void read(T &x){
    int f=1;char c=getchar();x=0;
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}
const int N=521,MOD=998244353;
int n,m,c[N],a[N],id[N],ans;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    read(n);read(m);cin>>s;
    rep(i,1,n) read(c[i]),id[i]=i;
    if(m==n){
        int ans=1;
        rep(i,2,n) ans=1ll*ans*i%MOD;
        rep(i,1,n) if(s[i-1]=='0') ans=0;
        rep(i,1,n) if(c[i]==0) ans=0;
        printf("%d\n",ans);
        return 0;
    }

    do{
        rep(i,1,n) a[i]=0;
        int cnt=0;
        rep(i,1,n){
            int lost=i-cnt-1;
            if(s[i-1]=='0'||lost>=c[id[i]]) a[i]=0;
            else a[i]=1,cnt++;
        }
        if(cnt>=m) ans++;
    }while(next_permutation(id+1,id+n+1));
    printf("%d\n",ans);
    return 0;
}
