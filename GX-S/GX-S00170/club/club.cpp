#include <bits/stdc++.h>
struct s{
    int a,a1;
}d[1000000];
bool cmp(s c,s b)
{
    if(c.a!=b.a)
    {
        return c.a>b.a;
    }
}
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t,n,m[3]={0},sum[3]={0},b,sum1=0;
    cin>>t>>n;
    for(int i=1;i<=t;i++)
    {
        sum1=0;
        b=n/2;
        for(int j=1;j<=n;j++)
        {
            int max=0;
            for(int k=1;k<=3;k++)
            {
                cin>>d[k].a;
                d[k].a1=k;
            }
            sort(d+1,d+n+1,cmp);
            int o=d[j].a1;
            for(int y=1;y<=n;y++)
            {
                if(m[o]<b)
                {
                    m[o]++;
                    sum[o]+=d[o].a;
                }
                else
                {
                    o++;
                }
            }
        }
        for(int l=1;l<=n;l++)
        {
            if(m[l]<=b)
            {
                sum1+=sum[l];
            }
        }
        cout<<sum1<<endl;
        cin>>n;
    }
    return 0;
    }
