#include <bits/stdc++.h>
using namespace std;
int n,t,nam,nbm,ncm;
int num,ans;
struct club
{
    int a1,a2,a3;
}a[100005];

bool cmp(club a,club b)
{
    return max( {a.a1 ,a.a2 ,a.a3 } ) >max ({b.a1 ,b.a2 ,b.a3 });
}

void dfs(int i)
{
    if (a[i].a1==max({a[i].a1 ,a[i].a2 ,a[i].a3 }) )
    {
        if (nam=n/2)
        {
            a[i].a1=-1;
            dfs(i);
        }
        else
        {
            nam++;
            num+=a[i].a1;
        }
    }
    if (a[i].a2==max({a[i].a1 ,a[i].a2 ,a[i].a3 }) )
    {
        if (nbm==n/2)
        {
            a[i].a2=-1;
            dfs(i);
        }
        else
        {
            nbm++;
            num+=a[i].a2;
        }

    }
    if (a[i].a3==max({a[i].a1 ,a[i].a2 ,a[i].a3 }) )
    {
        if (ncm==n/2)
        {
            a[i].a3=-1;
            dfs(i);
        }
        else
        {
            ncm++;
            num+=a[i].a3;
        }

    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        num=0,ans=0;
        nam=0,nbm=0,ncm=0;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
            ans+=max({a[i].a1 ,a[i].a2 ,a[i].a3 });
        }
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;i++)
        {
            if (a[i].a1==max({a[i].a1 ,a[i].a2 ,a[i].a3 }) )
            {
                if (nam==n/2)
                {
                    a[i].a1=-1;
                    dfs(i);
                    continue;
                }
                nam++;
                num+=a[i].a1;
            }
            if (a[i].a2==max({a[i].a1 ,a[i].a2 ,a[i].a3 }) )
            {
                if (nbm==n/2)
                {
                    a[i].a2=-1;
                    dfs(i);
                    continue;
                }
                nbm++;
                num+=a[i].a2;
            }
            if (a[i].a3==max({a[i].a1 ,a[i].a2 ,a[i].a3 }) )
            {
                if (ncm==n/2)
                {
                    a[i].a3=-1;
                    dfs(i);
                    continue;
                }
                ncm++;
                num+=a[i].a3;
            }

        }
        cout<<num<<endl;
    }
    return 0;
}
