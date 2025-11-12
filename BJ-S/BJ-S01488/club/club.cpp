#include <bits/stdc++.h>
using namespace std;
int t,n,m,ans,a[100001][4];
vector<int> club[4];
int mincha(int x)
{
    int maxx=0;
    for (int i=1;i<=3;i++)
    {
        if (i==m)
            continue;
        maxx=max(maxx,a[x][i]);
    }
    return a[x][m]-maxx;
}
bool cmp(int x,int y)
{
    return mincha(x)<mincha(y);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans=0;
        m=0;
        for (int i=1;i<=3;i++)
            club[i].clear();
        cin>>n;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=3;j++)
                cin>>a[i][j];
        for (int i=1;i<=n;i++)
            if (a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
            {
                club[1].push_back(i);
                ans+=a[i][1];
            }
            else if (a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
            {
                club[2].push_back(i);
                ans+=a[i][2];
            }
            else
            {
                club[3].push_back(i);
                ans+=a[i][3];
            }
        if (club[1].size()>n/2)
            m=1;
        if (club[2].size()>n/2)
            m=2;
        if (club[3].size()>n/2)
            m=3;
        if (!m)
        {
            cout<<ans<<endl;
            continue;
        }
        sort(club[m].begin(),club[m].end(),cmp);
        for (int i=0;i<club[m].size()-n/2;i++)
            ans-=mincha(club[m][i]);
        cout<<ans<<endl;
    }
}