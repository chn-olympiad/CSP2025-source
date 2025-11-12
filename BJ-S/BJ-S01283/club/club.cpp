#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum=0;
bool cmp(pair<ll,ll> x, pair<ll,ll> y)
{
    return x.first>y.first;
}
ll a1[3]={0,0,0};
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        sum=0;

        for(int k=0;k<3;k++)
        {
            a1[i]=0;
        }
        ll t;
        cin>>t;
        a1[0]=0;
        a1[1]=0;
        a1[2]=0;
        for(int j=0;j<t;j++)
        {
            pair<ll,ll> a[3];
            cin>>a[0].first>>a[1].first>>a[2].first;
            a[0].second=1;a[1].second=2;a[2].second=3;
            sort(a,a+3,cmp);
            for(int k=0;k<3;k++)
            {
                if(a[k].second==1&&a1[0]<=t/2)
                {
                    sum+=a[k].first;
                    a1[0]++;
                    break;
                }
                if(a[k].second==2&&a1[1]<=t/2)
                {
                    sum+=a[k].first;
                    a1[1]++;
                    break;
                }
                if(a[k].second==3&&a1[2]<=t/2)
                {
                    sum+=a[k].first;
                    a1[2]++;
                    break;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
