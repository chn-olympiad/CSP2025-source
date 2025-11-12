#include<bits/stdc++.h>
namespace xcy{
typedef long long ll;
const int MAXN=100005;
ll a[MAXN][3],v[MAXN],b[MAXN],cnt[3],t,n,m,i,j,k,ans;

inline void fr(ll &X){ll A=1;X=0;char C=getchar();while(!isdigit(C)&&C!='-')C=getchar();
    if(C=='-')A=-1,C=getchar();while(isdigit(C))X=X*10+C-'0',C=getchar();X*=A;}
inline void out(const ll X){if(!X)return;out(X/10);putchar(X%10+'0');}
inline void fo(ll X,const char C=' '){if(X<0)putchar('-'),X=-X;if(!X)putchar('0');out(X);putchar(C);}

int mian()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    fr(t);while(t--){ans=0;memset(cnt,0,sizeof(cnt));
    fr(n);for(i=1;i<=n;++i)for(j=0;j<=2;++j)fr(a[i][j]);
    for(i=1;i<=n;ans+=a[i][b[i]],++cnt[b[i]],++i)
        for(j=1,b[i]=0;j<=2;++j)if(a[i][j]>a[i][b[i]])b[i]=j;
    for(j=0;j<=2;++j)if(cnt[j]>n/2)
    {
        for(i=1,m=0;i<=n;++i)if(b[i]==j)
        {
            for(k=v[++m]=0;k<=2;++k)if(j!=k)
                v[m]=std::max(v[m],a[i][k]);v[m]-=a[i][j];
        }
        std::sort(v+1,v+m+1,std::greater<ll>());
        for(i=1;i<=cnt[j]-n/2;++i)ans+=v[i];
    }
    fo(ans,'\n');
    }return 0;
}}
int main(){return xcy::mian();}