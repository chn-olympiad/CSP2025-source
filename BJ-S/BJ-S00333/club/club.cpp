#include <bits/stdc++.h>
using namespace std;
#define INPUT_FILE "club.in"
#define OUTPUT_FILE "club.out"
constexpr int N=1e5+3;
int T,n,a[N][3];
vector<int> bkt[3];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0;i<3;i++)
            bkt[i].clear();
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            int id=0,mx=max({a[i][0],a[i][1],a[i][2]}),lmx=0;
            for(int j=0;j<3;j++)
                if(mx==a[i][j])
                {
                    id=j;
                    break;
                }
            for(int j=0;j<3;j++)
                if(j!=id) lmx=max(lmx,a[i][j]);
            bkt[id].push_back(lmx-mx);
            ans+=mx;
        }
        for(int i=0;i<3;i++)
            if(bkt[i].size()>(n>>1))
            {
                sort(bkt[i].begin(),bkt[i].end());
                for(;bkt[i].size()>n>>1;bkt[i].pop_back())
                    ans+=bkt[i].back();
            }
        cout<<ans<<'\n';
    }
    return 0;
}
inline __attribute((constructor)) void init_io()
{
#ifdef INPUT_FILE
    freopen(INPUT_FILE,"r",stdin);
#endif
#ifdef OUTPUT_FILE
    freopen(OUTPUT_FILE,"w",stdout);
#endif
#ifndef RUN_ON_LOCAL
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
#endif
}