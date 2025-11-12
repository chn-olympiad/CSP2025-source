#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;

struct node
{
    long long d1,d2,d3;
    long long maxmax,maxmin;
}a[maxn];

int n;
int d1,d2,d3;
long long ans=0;
int m1[maxn],m2[maxn],m3[maxn];

void init()
{
    d1=0,d2=0,d3=0;
    ans=0;
    m1[0]=maxn;
    m2[0]=maxn;
    m3[0]=maxn;
}

void solve()
{
    init();
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].d1>>a[i].d2>>a[i].d3;
        if(a[i].d1>=a[i].d2&&a[i].d1>=a[i].d3)
        {
            a[i].maxmax=a[i].d1;
            d1++;
            m1[d1]=min((a[i].d1-a[i].d2),(a[i].d1-a[i].d3));
        }
        else if(a[i].d2>=a[i].d1&&a[i].d2>=a[i].d3)
        {
            a[i].maxmax=a[i].d2;
            d2++;
            m2[d2]=min((a[i].d2-a[i].d1),(a[i].d2-a[i].d3));
        }
        else
        {
            a[i].maxmax=a[i].d3;
            d3++;
            m3[d3]=min((a[i].d3-a[i].d2),(a[i].d3-a[i].d1));
        }
        ans+=a[i].maxmax;
    }
    if(d1>n/2)
    {
        sort(m1+1,m1+d1+1);
        for(int i=1;i<=d1-n/2;i++)
        {
            ans-=m1[i];
        }
    }
    if(d2>n/2)
    {
        sort(m2+1,m2+d2+1);
        for(int i=1;i<=d2-n/2;i++)
        {
            ans-=m2[i];
        }
    }
    if(d3>n/2)
    {
        //for(int i=1;i<=d3;i++)cout<<"+++"<<m3[i]<<endl;
        sort(m3+1,m3+d3+1);
        //for(int i=1;i<=d3;i++)cout<<"---"<<m3[i]<<endl;
        for(int i=1;i<=d3-n/2;i++)
        {
            ans-=m3[i];
        }
    }
    cout<<ans<<endl;
}

int main()
{
    int T;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}
