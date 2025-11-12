#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    {
        int n;cin>>n;
        vector<int> a[3];
        for(int i=0;i<3;i++)
        a[i].resize(n+1);
        for(int i=1;i<=n;i++)
        cin>>a[0][i]>>a[1][i]>>a[2][i];
        vector<int> vc[3];int ans=0;
        for(int i=1;i<=n;i++)
        {
            int t=0;
            if(a[t][i]<a[1][i])t=1;
            if(a[t][i]<a[2][i])t=2;
            ans+=a[t][i];
            vc[t].push_back(max(a[(t+1)%3][i],a[(t+2)%3][i])-a[t][i]);
        }int t=0;if(vc[1].size()>vc[t].size())t=1;
        if(vc[2].size()>vc[t].size())t=2;
        if(vc[t].size()<=n/2)cout<<ans<<'\n';
        else
        {
            sort(vc[t].begin(),vc[t].end());
            reverse(vc[t].begin(),vc[t].end());
            for(int i=0;i<vc[t].size()-n/2;i++)
            ans+=vc[t][i];cout<<ans<<'\n';
        }
    }return 0;
}
