#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5;
int f[N][3],num[4];
vector<int>v;

bool _0(int i)
{
    if(f[i][0]>=f[i][1]&&f[i][0]>=f[i][2])
        return 1;
    return 0;
}

bool _1(int i)
{
    if(f[i][1]>f[i][0]&&f[i][1]>=f[i][2])
        return 1;
    return 0;
}

bool _2(int i)
{
    if(f[i][2]>f[i][0]&&f[i][2]>f[i][1])
        return 1;
    return 0;
}

signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,ans=0;
        cin>>n,num[0]=num[1]=num[2]=0;
        v.clear();

        for(int i=1;i<=n;i++)
        {
            int a,b,c;
            cin>>f[i][0]>>f[i][1]>>f[i][2];
            if(_0(i)) num[0]++,ans+=f[i][0];
            if(_1(i)) num[1]++,ans+=f[i][1];
            if(_2(i)) num[2]++,ans+=f[i][2];
        }

        if(num[0]>=n/2)
        {
            for(int i=1;i<=n;i++)
                if(_0(i)) v.push_back(
                    min(f[i][0]-f[i][1],
                        f[i][0]-f[i][2]));

            sort(v.begin(),v.end());
            for(int i=0;i<num[0]-n/2;i++)
                ans-=v[i];
        }

        if(num[1]>=n/2)
        {
            for(int i=1;i<=n;i++)
                if(_1(i)) v.push_back(
                    min(f[i][1]-f[i][0],
                        f[i][1]-f[i][2]));

            sort(v.begin(),v.end());
            for(int i=0;i<num[1]-n/2;i++)
                ans-=v[i];
        }

        if(num[2]>=n/2)
        {
            for(int i=1;i<=n;i++)
                if(_2(i)) v.push_back(
                    min(f[i][2]-f[i][1],
                        f[i][2]-f[i][0]));

            sort(v.begin(),v.end());
            for(int i=0;i<num[2]-n/2;i++)
                ans-=v[i];
        }

        cout<<ans<<'\n';
    }
    return 0;
}
