#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        queue<ll>q1;
        ll cnt1=0,cnt2=0,cnt3=0;
        for(int i=1;i<=n;i++)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            if(a>max(a,b));
            {
                if(cnt1<n/2)
                {
                    q1.push(a);
                    cnt1++;
                }
                else if(b>c&&cnt2<=n/2)
                {
                    q1.push(b);
                    cnt2++;
                }
                else
                {
                    q1.push(c);
                    cnt3++;
                }
            }
            if(b>max(a,c));
            {
                if(cnt2<n/2)
                {
                    q1.push(b);
                    cnt2++;
                }
                else if(a>c&&cnt1<=n/2)
                {
                    q1.push(a);
                    cnt1++;
                }
                else
                {
                    q1.push(c);
                    cnt3++;
                }
            }
            if(c>max(a,b));
            {
                if(cnt3<n/2)
                {
                    q1.push(c);
                    cnt3++;
                }
                else if(a>=b&&cnt1<=n/2)
                {
                    q1.push(a);
                    cnt1++;
                }
                else
                {
                    q1.push(b);
                    cnt2++;
                }
            }
        }
        ll ans=0;
        while(!q1.empty())
        {
            ll s=q1.front();
            ans+=s;
            q1.pop();
        }
        cout<<ceil(ans/2)<<endl;
    }
}
