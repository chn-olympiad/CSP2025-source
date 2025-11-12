#include<bits/stdc++.h>
using namespace std;
// struct p
// {
//     int a,b,c;
// }a[100005];
// int d[100005];
vector<int>ma,mb,mc;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int a1=0,b1=0,c1=0;
        int n;
        cin>>n;
        long long ans=0;
        ma.clear();
        mb.clear();
        mc.clear();
        for(int i=1;i<=n;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            int mx=max(a,max(b,c));
            if(a==mx)
            {
                a1++;
                int mx2=max(b,c);
                int d=mx-mx2;
                ma.push_back(d);
            }
            else if(b==mx)
            {
                b1++;
                int mx2=max(a,c);
                int d=mx-mx2;
                mb.push_back(d);
            }
            else
            {
                c1++;
                int mx2=max(b,a);
                int d=mx-mx2;
                mc.push_back(d);
            }
            ans+=mx;
        }
        if(a1>n/2)
        {
            sort(ma.begin(),ma.end());
            for(auto i:ma)
            {
                if(a1<=n/2)break;
                a1--;
                ans-=i;
            }
        }
        if(b1>n/2)
        {
            sort(mb.begin(),mb.end());
            for(auto i:mb)
            {
                if(b1<=n/2)break;
                b1--;
                ans-=i;
            }
        }
        if(c1>n/2)
        {
            sort(mc.begin(),mc.end());
            for(auto i:mc)
            {
                if(c1<=n/2)break;
                c1--;
                ans-=i;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}