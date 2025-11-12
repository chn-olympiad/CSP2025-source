#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000010][4];
int ch[1000010];
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    int t; cin>>t; while(t--)
    {
        cin>>n;
        for(int i=1; i<=n; ++i) cin>>a[i][1]>>a[i][2]>>a[i][3];
        int ans=0,cnt[4]={0,0,0,0};
        for(int i=1; i<=n; ++i)
        {
            int ax=-1e18,wz;
            for(int j=1; j<=3; ++j)
            {
                if(ax<a[i][j]) ax=a[i][j],wz=j;
            }
            ans+=ax,ch[i]=wz,++cnt[wz];
        }
        int more=0;
        for(int i=1; i<=3; ++i)
        {
            if(cnt[i]>n/2) more=i;
        }
        if(more==0) cout<<ans<<'\n';
        else
        {
            vector<int> gt;
            for(int i=1; i<=n; ++i)
            {
                if(ch[i]==more)
                {
                    int ax=-1e18;
                    for(int j=1; j<=3; ++j)
                    {
                        if(j!=more) ax=max(ax,a[i][j]);
                    }
                    gt.push_back(a[i][more]-ax);
                }
            }
            sort(gt.begin(),gt.end());
            for(int i=0; i<cnt[more]-n/2; ++i) ans-=gt[i];
            cout<<ans<<'\n';
        }
    }
    return 0;
}
