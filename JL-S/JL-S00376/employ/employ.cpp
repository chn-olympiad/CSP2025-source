#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m,a[15],b[15];
string s;
void solve1()
{
    for(int i=1;i<=n;i++)
        b[i]=i;
    int ans=0;
    do
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(cnt>=a[b[i]])
                cnt++;
            else if(s[i-1]=='0')
                cnt++;
        }
        if(n-cnt>=m)
            ans++;
    }
    while(next_permutation(b+1,b+n+1));
    printf("%d\n",ans);
    exit(0);
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>s;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if(n<=10)
        solve1();
    if(m==n)
    {
        int flag=1;
        for(int i=1;i<=n;i++)
            if(a[i]==0||s[i-1]=='0')
                flag=0;
        if(!flag)
        {
            puts("0");
            return 0;
        }
        long long res=1;
        for(int i=1;i<=n;i++)
            res=(res*i)%mod;
        printf("%lld\n",res);
        return 0;
    }
    puts("0");
    return 0;
}
