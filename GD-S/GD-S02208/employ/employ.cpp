#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
inline int read(){
    int x=0,flag=0; char c=getchar();
    while(c<'0' || c>'9'){if(c=='-') flag=1; c=getchar();}
    while(c>='0' && c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    return flag ? ~(x-1) : x;
}

typedef long long ll;
const int N=5e6+5,mod=998244353;
int n,m;
char s[N];
ll cnt,ans=1;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=read(),m=read();
    scanf("%s",s+1);
    for(int i=1; i<=n; i++) cnt+=(read()==0);
    if(n-cnt<m) return puts("0"),0;
    for(int i=n; i>cnt; i--) ans=(ans*i)%mod;
    printf("%lld\n",ans);
    return 0;
}