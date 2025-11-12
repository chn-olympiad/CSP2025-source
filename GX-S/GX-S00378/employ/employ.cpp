#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll M=998'244'353;
int n,m,a[505],id[505];
char s[505];
bool check()
{
    int now=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(now>=a[id[i]]) now++;
        else if(s[i]=='1') cnt++;
        else now++;
        if(cnt+n-i<m) return 0;
    }
    return cnt>=m;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d\n%s",&n,&m,s+1);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(n==m)
    {
        int f=1;
        for(int i=1;i<=n;i++)
            if(s[i]=='0'||a[i]==0)
            {
                f=0;
                break;
            }
        if(f)
        {
            ll ans=1;
            for(ll i=2;i<=n;i++) (ans*=i)%=M;
            printf("%lld",ans);
        }
        else printf("0");
        return 0;
    }
    for(int i=1;i<=n;i++) id[i]=i;
    int ans=0;
    do
    {
        if(check()) ans++;
        if(ans==M) ans=0;
    }while(next_permutation(id+1,id+n+1));
    printf("%d",ans);
    return 0;
}

