#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5;
char ch[N];
int n,m,ans;
struct node
{
    int w,id=1;
    friend bool operator <(node u,node v)
    {
        return u.id<v.id;
    }
}s[N];
long long F(int x)
{
    long long ret=1;
    for(int i=2;i<=x;i++)
    {
        ret*=i;
        ret%=998244353;
    }
    return ret;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",ch+1);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&s[i].w);
        s[i].id=i;
    }
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        if(ch[i]=='0')
        {
            flag=false;
            break;
        }
    }
    if(flag)
    {
        printf("%lld",F(n));
        return 0;
    }
    do
    {
        int cnt=0,d=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i].w<=cnt)
            {
                cnt++;
                continue;
            }
            if(ch[i]=='1') d++;
            else cnt++;
            if(d>=m) break;
        }
        if(d>=m) ans++;
        ans%=998244353;
    }while(next_permutation(s+1,s+n+1));
    printf("%lld",ans);
    return 0;
}
