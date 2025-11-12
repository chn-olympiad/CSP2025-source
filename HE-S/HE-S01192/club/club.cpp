#include<bits/stdc++.h>
using namespace std;
int n,a[100010][5],t,ans;
multimap<int,int> mp[5];
multimap<int,int>::iterator it;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int i,j,ma[2];
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d",&n);
        for(i=1; i<=n; i++)
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        for(i=1; i<=n; i++)
        {
            ma[0]=1; ma[1]=0;
            for(j=1; j<=3; j++)
            {
                if(a[i][j]>a[i][ma[0]])
                    ma[0]=j;
            }
            for(j=1; j<=3; j++)
            {
                if(a[i][j]>a[i][ma[1]] && j!=ma[0])
                    ma[1]=j;
            }
            mp[ma[0]].insert(make_pair(a[i][ma[0]]-a[i][ma[1]],a[i][ma[0]]));
            ans=ans+a[i][ma[0]];
        }
//        cout<<ans<<'\n';
        for(i=1; i<=3; i++)
        {
            if(mp[i].size()>n/2)
            {
//                for(it=mp[i].begin(); it!=mp[i].end(); it++)
//                    cout<<it->first<<' '<<it->second<<'\n';
                while(mp[i].size()>n/2)
                {
//                    cout<<' '<<(*mp[i].begin()).first<<'\n';
                    ans=ans-(*mp[i].begin()).first;
                    mp[i].erase(mp[i].begin());
                }
                break;
            }
        }
        for(i=1; i<=3; i++)
            mp[i].clear();
        cout<<ans<<'\n';
    }
    return 0;
}
