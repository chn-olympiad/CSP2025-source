#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=998244353;
ll n,m;
vector<long long> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n==3)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        ll p=max(a,max(b,c));
        if(p*2<a+b+c) cout<<1;
        else cout<<0;
        return 0;
    }
    long long cnt=0;
    for(int i=0;i<n;i++)
    {
        long long x;cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end(),greater<long long>());
    if(v[0]!=1)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=i+2;j<n;j++)
            {
                ll xx=0,yy=-1;
                for(int k=i;k<=j;k++)
                {
                    xx+=v[k];
                    yy=max(v[k],yy);
                }
                if(yy*2<xx)
                {

                    cnt++;
                }
            }
        }
        cout<<cnt;
    }
    return 0;
}
