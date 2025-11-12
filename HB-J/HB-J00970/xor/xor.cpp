#include <bits/stdc++.h>
using namespace std;
int n,k,s[500005],a[500005],book[500005],p=0,cnt=1,t;
struct node
{
    int u,v;
}e[500005];
bool cmp(node x,node y)
{
    if(x.u==y.u)
        return x.v<y.v;
    return x.u<y.u;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","W",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+(a[i]||a[i-1]);
    }
    for(int i=1;i<=n;i++)
        if(a[i]==k)
        {
            p++;
            e[p].u=i;
            e[p].v=i;
        }
    for(int i=1;i<=n-1;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(s[j]-s[i]==k)
            {
                p++;
                e[p].u=i;
                e[p].v=j;
                break;
            }
        }
    }
    sort(e+1,e+1+p,cmp);
    t=1;
    for(int i=2;i<=p;i++)
    {
        cnt++;
        if(e[i].u<e[t].v && e[t].v<e[i].v)
        {
            cnt--;
            book[i]=1;

        }
        else if(e[i].u<e[t].v && e[t].v>e[i].v)
        {
            cnt--;
            book[t]=1;
            t=i;
        }
        else if(e[i].u==e[t].u && e[t].v<=e[i].v)
        {
            cnt--;
            book[i]=1;
        }
        else if(e[i].u==e[t].v)
        {
            cnt--;
            book[i]=1;
        }
        else if(e[i].v==e[t].v)
        {
            cnt--;
            book[i]=1;
        }
        else
        {
            t=i;
            continue;
        }


    }
    cout<<cnt;
    return 0;
}
