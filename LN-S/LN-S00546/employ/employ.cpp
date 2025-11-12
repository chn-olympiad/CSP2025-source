#include <bits/stdc++.h>
using namespace std;
const int P=998244353;
int n,m,cnt,c[501];
long long ans=1;
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
    }
    sort(c+1,c+n+1);
    for(int i=1;i<=n;i++)
    {
        if(c[i]<=cnt)
        {
            cnt++;
        }
    }
    n-=cnt;
    for(int i=1;i<=n;i++)
    {
        ans*=i;
        ans%=P;
    }
    printf("%lld",ans);
    return 0;
}
