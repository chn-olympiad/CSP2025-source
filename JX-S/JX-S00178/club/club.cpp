#include<bits/stdc++.h>
using namespace std;
int t;
long long n;
struct MEMBER{
    long long a,b,c;
    long long fc;
};
MEMBER m[100005];
void solve()
{
    set<pair<long long,long long> >d1,d2,d3;
    long long ans=0;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        long long a,b,c,fc;
        cin>>m[i].a>>m[i].b>>m[i].c;
        a=m[i].a;b=m[i].b;c=m[i].c;
        long long h=max(m[i].a,max(m[i].b,m[i].c));
        if(h==a)
        {
            fc=h-max(b,c);
        }
        if(h==b)
        {
            fc=h-max(a,c);
        }
        if(h==c)
        {
            fc=h-max(b,a);
        }
        m[i].fc=fc;
        //cout<<fc<<" ";
    }
    for(long long i=1;i<=n;i++)
    {
        long long a=m[i].a,b=m[i].b,c=m[i].c,fc=m[i].fc;
        if(a>=b && a>=c)
        {
            d1.insert({fc,i});
            if(d1.size()>n/2)
            {
                long long h=d1.begin()->second;
                d1.erase(d1.begin());
                if(m[h].b>=m[h].c)
                {
                    d2.insert({m[h].fc,h});
                }
                else
                {
                    d3.insert({m[h].fc,h});
                }
            }
        }
        else if(b>=c && b>=a)
        {
            d2.insert({fc,i});
            if(d2.size()>n/2)
            {
                long long h=d2.begin()->second;
                d2.erase(d2.begin());
                if(m[h].a>=m[h].c)
                {
                    d1.insert({m[h].c,h});
                }
                else
                {
                    d3.insert({m[h].fc,h});
                }
            }
        }
        else if(c>=b && c>=a)
        {
            d3.insert({fc,i});
            if(d3.size()>n/2)
            {
                long long h=d3.begin()->second;
                d3.erase(d3.begin());
                if(m[h].a>=m[h].b)
                {
                    d1.insert({m[h].fc,h});
                }
                else
                {
                    d2.insert({m[h].fc,h});
                }
            }
        }
    }
    //cout<<"\n";
    while(d1.size())
    {
        long long h=d1.begin()->second;
        //cout<<h<<" ";
        ans+=m[h].a;
        d1.erase(d1.begin());
    }
    while(d2.size())
    {
        long long h=d2.begin()->second;
        //cout<<h<<" ";
        ans+=m[h].b;
        d2.erase(d2.begin());
    }
    while(d3.size())
    {
        long long h=d3.begin()->second;
        //cout<<h<<" ";
        ans+=m[h].c;
        d3.erase(d3.begin());
    }
    cout<<ans<<"\n";
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
