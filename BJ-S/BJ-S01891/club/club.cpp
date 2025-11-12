#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    vector<int> v1,v2;
    cin>>t;
    while(t--)
    {
        int a,b,c,ans=0,sumb=0,sumc=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a>>b>>c;
            v1.push_back(a);
            v2.push_back(b);
            sumb+=b;
            sumc+=c;
        }
        if(sumb==0&&sumc==0)
        {
            sort(v1.begin(),v1.end(),greater<int>());
            v1.resize(v1.size()>>1);
            for(auto i:v1) ans+=i;
        }
        else
            for(int i=0;i<n;i++)
                ans+=max(v1[i],v2[i]);
        cout<<ans<<"\n";
        ans=0;
        v1.clear();
        v2.clear();
    }
    return 0;
}