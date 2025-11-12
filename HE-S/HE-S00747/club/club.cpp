#include<bits/stdc++.h>
using namespace std;
using llt=long long;
const llt N=200100;
llt T,n,a[N][4],cnt[4],ans;
vector<llt> vec[4];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);ans=0;
        for(int i=1;i<=n;i++) 
        {
            scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
            llt M=max({a[i][1],a[i][2],a[i][3]});ans+=M;
            if(a[i][1]==M) vec[1].push_back(M-max(a[i][2],a[i][3]));
            else if(a[i][2]==M) vec[2].push_back(M-max(a[i][1],a[i][3]));
            else if(a[i][3]==M) vec[3].push_back(M-max(a[i][1],a[i][2]));
        }
        for(int i=1;i<=3;i++)
        {
            llt S=vec[i].size();
            if(S>n/2)
            {
                sort(vec[i].begin(),vec[i].end());
                for(int j=0;j<S-n/2;j++) ans-=vec[i][j];
            }
            vec[i].clear();
        }
        printf("%lld\n",ans);
    }
    return 0;
}