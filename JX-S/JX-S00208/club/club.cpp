#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
struct node
{
    ll a,b,c;
};
bool cmp(node x,node y)
{
    if(x.a<x.b)swap(x.a,x.b);
    if(x.b<x.c)swap(x.b,x.c);
    if(x.a<x.b)swap(x.a,x.b);
    if(y.a<y.b)swap(y.a,y.b);
    if(y.b<y.c)swap(y.b,y.c);
    if(y.a<y.b)swap(y.a,y.b);
    if(x.a+y.b==x.b+y.a)return x.b+y.c>x.c+y.b;
    return x.a+y.b>x.b+y.a;
}
ll max1(ll a,ll b,ll c)
{
    return max(a,max(b,c));
}
void work()
{
    node d[100005];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>d[i].a>>d[i].b>>d[i].c;
    sort(d+1,d+n+1,cmp);
    ll ca=0,cb=0,cc=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        ll ta=d[i].a,tb=d[i].b,tc=d[i].c;
        if(max1(ta,tb,tc)==ta)
        {
            if(ca<n/2)
            {
                ans+=ta;
                ca++;
            }
            else
            {
                if(max(tb,tc)==tb)
                {
                    ans+=tb;
                    cb++;
                }
                else
                {
                    ans+=tc;
                    cc++;
                }
            }
        }
        else if(max1(ta,tb,tc)==tb)
        {
            if(cb<n/2)
            {
                ans+=tb;
                cb++;
            }
            else
            {
                if(max(ta,tc)==ta)
                {
                    ans+=ta;
                    ca++;
                }
                else
                {
                    ans+=tc;
                    cc++;
                }
            }
        }
        else
        {
            if(cc<n/2)
            {
                ans+=tc;
                cc++;
            }
            else
            {
                if(max(ta,tb)==ta)
                {
                    ans+=ta;
                    ca++;
                }
                else
                {
                    ans+=tb;
                    cb++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return;
}
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    while(t--)work();
    return 0;
}
