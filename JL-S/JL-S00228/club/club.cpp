#include <bits/stdc++.h>
using namespace std;
int n,a[200005][4],xyz[4],k[200005];
bool cmp(int x,int y)
{
    return a[x][a[x][0]]>a[y][a[y][0]];
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    for(int qw=1;qw<=T;qw++)
    {
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            k[i]=i;
            if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])
            {
                a[i][0]=1;

            }
            if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])
            {
                a[i][0]=2;
            }
            if(a[i][3]>a[i][2]&&a[i][3]>a[i][1])
            {
                a[i][0]=3;
            }
        }
        sort(k+1,k+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            if(xyz[a[k[i]][0]]<n/2)
            {
                xyz[a[k[i]][0]]++;
                ans+=a[k[i]][a[k[i]][0]];
            }
            else
            {
                if(a[k[i]][0]==1)
                {
                    xyz[2]++;
                    ans+=a[k[i]][2];

                }
                if(a[k[i]][0]==2)
                {
                    xyz[1]++;
                    ans+=a[k[i]][1];

                }
            }
        }
        cout<<ans<<endl;


    }
    return 0;
}
