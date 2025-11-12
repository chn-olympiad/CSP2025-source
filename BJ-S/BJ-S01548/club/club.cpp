#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<ll,vector<ll>,greater<ll>> p1,p2,p3;
ll a1[100010],a2[100010],a3[100010];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll t;
    cin>>t;
    while(t--)
    {
        while(!p1.empty())
        {
            p1.pop();
        }
        while(!p2.empty())
        {
            p2.pop();
        }
        while(!p3.empty())
        {
            p3.pop();
        }
        ll n,c1=0,c2=0,c3=0,tot=0;
        cin>>n;
        for(ll i=1;i<=n;i++)
        {
            ll x,y,z;
            cin>>x>>y>>z;
            if(max({x,y,z})==x)
            {
                tot+=x;
                c1++;
                p1.push(x-max(y,z));
                if(max(y,z)==y)
                    a1[x-y]=2+x-y;
                else
                    a1[x-z]=3+x-z;
            }
            else if(max({x,y,z})==y)
            {
                tot+=y;
                c2++;
                p2.push(y-max(x,z));
                if(max(x,z)==x)
                    a2[y-x]=1+y-x;
                else
                    a2[y-z]=3+y-z;
            }
            else
            {
                tot+=z;
                c3++;
                p3.push(z-max(x,y));
                if(max(y,x)==y)
                    a3[z-y]=2+z-y;
                else
                    a3[z-x]=1+z-x;
            }
        }
        while(2*max({c1,c2,c3})>n)
        {
            if(max({c1,c2,c3})==c1)
            {
                tot-=p1.top();
                c1--;
                if(a1[p1.top()]==2+p1.top()) c2++;
                else c3++;
                p1.pop();
            }
            else if(max({c1,c2,c3})==c2)
            {
                tot-=p2.top();
                c2--;
                if(a2[p2.top()]==1+p2.top()) c1++;
                else c3++;
                p2.pop();
            }
            else
            {
                tot-=p3.top();
                c3--;
                if(a3[p3.top()]==2+p3.top()) c2++;
                else c1++;
                p3.pop();
            }
        }
        cout<<tot<<endl;
    }
    return 0;
}
