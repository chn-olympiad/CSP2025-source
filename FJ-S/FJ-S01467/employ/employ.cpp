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
const int N=503,P=998244353;
int n,m,c[N],fc[N],cc[N],c1,f[1<<18|3][18],ans;
char s[N];

inline void A(int&x,int y){x+=y,x<P?0:x-=P;}

int main(){
    file(employ);
    rd(n,m),scanf("%s",s+1),fc[0]=1;
    fr(i,1,n)c1+=s[i]=='1',fc[i]=1ll*i*fc[i-1]%P;
    bool fl=0;
    fr(i,0,n-1)rd(c[i]),fl|=c[i]==0;
    if(m==n){
        if(c1<n||fl)puts("0");
        else cout<<fc[n];
        return 0;
    }
    if(m==1){
        ans=1;
        fr(i,1,n)cc[c[i]]++;
        int used=0;
        fr(i,1,n){
            cc[i]+=cc[i-1];
            if(s[i]=='1')ans=1ll*(P+cc[i-1]-used)%P*ans%P,used++;
        }
        return cout<<(P+fc[n]-1ll*ans*fc[n-used]%P)%P,0;
    }
    int full=(1<<n)-1;
    f[0][0]=1;
    fr(S,0,full){
        int cnt=__builtin_popcount(S);
        fr(i,0,cnt)if(f[S][i])fr(j,0,n-1)if(~S>>j&1)
            A(f[S|(1<<j)][i+(s[cnt+1]=='0'||i>=c[j])],f[S][i]);
    }
    fr(i,0,n-m)A(ans,f[full][i]);
    return cout<<ans,0;
}