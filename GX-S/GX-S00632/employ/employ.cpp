#include<bits/stdc++.h>
#define Inf (1ll<<60)
#define inf 0x3f3f3f3f
#define For(i,s,t) for(int i=(s);i<=(t);++i)
#define Down(i,s,t) for(int i=(s);i>=(t);--i)
#define eps 1e-9
typedef long long ll;
typedef unsigned long long ull;
inline int max(int x,int y){return x>y ? x : y;}
inline int min(int x,int y){return x<y ? x : y;}
inline ll max(ll x,ll y){return x>y ? x : y;}
inline ll min(ll x,ll y){return x<y ? x : y;}
inline void ckmn(int &x,int y){x=min(x,y);}
inline void ckmx(int &x,int y){x=max(x,y);}
inline void ckmn(ll &x,ll y){x=min(x,y);}
inline void ckmx(ll &x,ll y){x=max(x,y);}
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0' || '9'<c) f=(c=='-' ? -1 : 1),c=getchar();
    while('0'<=c && c<='9') x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return x*f;
}
using namespace std;
const int N=505,p=998244353;
int n,m,a[N],rk[N];
char s[N];
bool spA=true;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=read(),m=read();
    scanf("%s",s+1);
    For(i,1,n) a[i]=read();
    if(n<=10){
        iota(rk+1,rk+n+1,1);
        int ans=0;
        do{
            int cnt=0;
            For(i,1,n)
                if(i-cnt-1<a[rk[i]] && s[i]=='1')
                    ++cnt;
            ans+=(cnt>=m);
        }while(next_permutation(rk+1,rk+n+1));
        printf("%d\n",ans);
        return 0;
    }
    cout<<0;
    return 0;
}

