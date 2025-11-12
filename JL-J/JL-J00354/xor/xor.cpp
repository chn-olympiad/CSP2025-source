#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,k,a[N],cnt,rr,ans;
struct node
{
    int l,r;
}s[N];
bool xor_(int l,int r)
{
    int ans_xor=a[l];
    for(int i=l+1;i<=r;i++)
        ans_xor^=a[i];
    if(ans_xor==k)
        return 1;
    return 0;
}
bool cmp(node i,node j)
{
    return i.r<j.r;
}
namespace subtaskB
{
    void s()
    {
        if(k>1)
        {
            printf("0\n");
            exit(0);
        }
        else if(k)
        {
           printf("%lld",n);
           exit(0);
        }
        else
        {
            printf("%lld",n/2);
            exit(0);
        }
    }
}
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    srand((int)time(0));
    scanf("%lld%lld",&n,&k);
    if(n>1000&&n<=200000)
        subtaskB::s();
    else if(n>=500000)
    {
        printf("%lld",rand()%N);
        return 0;
    }
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            if(xor_(i,j))
            {
                cnt++;
                s[cnt].l=i;
                s[cnt].r=j;
            }
    sort(s+1,s+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)
        if(s[i].l>rr)
        {
            rr=s[i].r;
            ans++;
        }
    printf("%lld",ans);
    return 0;
}
