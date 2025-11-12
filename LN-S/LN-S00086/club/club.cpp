#include <bits/stdc++.h>
using namespace std;
struct member
{
    int f,s,t;
}a[100010];
int T,n,ans,num1,num2,num3,flagA,flagB;
int d[100010];
void dfs(int now,int sum)
{
    if(now>n)
    {
        ans=max(ans,sum);
        return;
    }
    if(num1<n/2)
    {
        num1++;
        dfs(now+1,sum+a[now].f);
        num1--;
    }
    if(num2<n/2)
    {
        num2++;
        dfs(now+1,sum+a[now].s);
        num2--;
    }
    if(num3<n/2)
    {
        num3++;
        dfs(now+1,sum+a[now].t);
        num3--;
    }
}
bool cmp(member x,member y)
{
    if(x.f>y.f)
        return 1;
    return 0;
}
void A()
{
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n/2;i++)
    {
        ans+=a[i].f;
    }
}
void B()
{
    for(int i=1;i<=n;i++)
    {
        ans+=a[i].f;
        d[i]=a[i].s-a[i].f;
    }
    sort(d+1,d+n+1);
    for(int i=n/2+1;i<=n;i++)
        ans+=d[i];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        flagA=flagB=1;
        ans=0;
        num1=num2=num3=0;
        memset(a,0,sizeof(a));
        memset(d,0,sizeof(d));
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].f>>a[i].s>>a[i].t;
            if(a[i].t!=0)
            {
                flagA=flagB=0;
            }
            if(a[i].s!=0)
                flagA=0;
        }
        if(flagA)
        {
            A();
        }
        else if(flagB)
        {
            B();
        }
        else
            dfs(1,0);
        cout<<ans<<"\n";
    }
    return 0;
}

