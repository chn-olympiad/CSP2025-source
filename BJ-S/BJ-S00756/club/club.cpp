#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;

int t,n;
int a[100005][5];
priority_queue<pii> qp1,qp2,qp3;

int xx(int a,int b,int c)
{
    vector<int> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
    sort(vec.begin(),vec.end());
    return vec[1];
}

signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        for(int i=1;i<=n;i++)
        {
            int mx=max(a[i][1],max(a[i][2],a[i][3])),mm=xx(a[i][1],a[i][2],a[i][3]);
            if(mx==a[i][1])
            {
                if(qp1.size()<n/2)
                {
                    qp1.push({mm-mx,mm});
                    ans+=mx;
                }
                else
                {
                    if(-qp1.top().fi<mx-mm)
                    {
                        ans-=-qp1.top().fi+qp1.top().se;
                        ans+=qp1.top().se;
                        ans+=mx;
                        qp1.pop();
                        qp1.push({mm-mx,mm});
                    }
                    else ans+=mm;
                }
            }
            else if(mx==a[i][2])
            {
                if(qp2.size()<n/2)
                {
                    qp2.push({mm-mx,mm});
                    ans+=mx;
                }
                else
                {
                    if(-qp2.top().fi<mx-mm)
                    {
                        ans-=-qp2.top().fi+qp2.top().se;
                        ans+=qp2.top().se;
                        ans+=mx;
                        qp2.pop();
                        qp2.push({mm-mx,mm});
                    }
                    else ans+=mm;
                }
            }
            else
            {
                if(qp3.size()<n/2)
                {
                    qp3.push({mm-mx,mm});
                    ans+=mx;
                }
                else
                {
                    if(-qp3.top().fi<mx-mm)
                    {
                        ans-=-qp3.top().fi+qp3.top().se;
                        ans+=qp3.top().se;
                        ans+=mx;
                        qp3.pop();
                        qp3.push({mm-mx,mm});
                    }
                    else ans+=mm;
                }
            }
        }
        while(qp1.size())qp1.pop();
        while(qp2.size())qp2.pop();
        while(qp3.size())qp3.pop();
        cout<<ans<<endl;
    }
}
