#include <iostream>
#include <queue>
#include <array>
#include <algorithm>
#define int long long
const int N=1e5+5;
int n,a[N][3],b[N][3],D;
bool cmp(int x,int y) {return a[D][x]>a[D][y];}
std::priority_queue<std::array<int,3> > q[3];
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    std::cin.tie(0)->sync_with_stdio(0);
    int T;
    std::cin>>T;
    while(T--)
    {
        std::cin>>n;
        int ans=0;
        for(int i=0;i<3;i++) while(!q[i].empty()) q[i].pop();       
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<3;j++) std::cin>>a[i][j],b[i][j]=j;
            D=i;
            std::sort(b[i],b[i]+3,cmp);
            ans+=a[i][b[i][0]];
            q[b[i][0]].push({a[i][b[i][1]]-a[i][b[i][0]],1,i});
        }
        for(;;)
        {
            int t=-1;
            for(int i=0;i<3;i++) if(q[i].size()>n/2) {t=i;break;}
            if(t==-1) break;
            auto u=q[t].top();
            q[t].pop();
            int i=u[2],j=u[1];
            ans+=u[0];
            if(j<2) q[b[i][j]].push({a[i][b[i][j+1]]-a[i][b[i][j]],j+1,i});
        }
        std::cout<<ans<<'\n';
    }
}