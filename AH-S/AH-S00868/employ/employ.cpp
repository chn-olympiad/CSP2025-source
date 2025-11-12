#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,m,a[505],b[505],num;
char s[505];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d %d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='1') ++num;
        scanf("%d",&a[i]);
    }
    if(num<m)
    {
        printf("0\n");
        return 0;
    }
    if(m==n||n>12)
    {
        ll now=1;
        for(int i=1;i<=n;++i)
        {
            now=now*i%mod;
            if(a[i]==0)
            {
                printf("0\n");
                return 0;
            }
        }
        printf("%lld\n",now);
        return 0;
    }
    int ans=0;
    for(int i=1;i<=n;++i) b[i]=i;
    do
    {
        int pre=0;
        for(int i=1;i<=n;++i)
        {
            if(s[i]=='1')
            {
                if(a[b[i]]<=pre) ++pre;
            }
            else ++pre;
        }
        ans+=(n-pre>=m);
    }while(next_permutation(b+1,b+1+n));
    printf("%d\n",ans);
    return 0;
}
///Ren5Jie4Di4Ling5%
