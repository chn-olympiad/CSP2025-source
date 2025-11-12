#include<bits/stdc++.h>
#define ll long long
using namespace std;
int p[100005][3];
int cn[3];
int q[100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,T,ans,m;
    cin>>T;
    while(T--)
    {
        cin>>n;
        ans=cn[0]=cn[1]=cn[2]=m=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>p[i][j];
            }
            if(p[i][0]>=p[i][1]&&p[i][0]>=p[i][2])
            {
                cn[0]++;
                ans+=p[i][0];
            }
            else
            {
                if(p[i][1]>=p[i][0]&&p[i][1]>=p[i][2])
                {
                    cn[1]++;
                    ans+=p[i][1];
                }
                else
                {
                    cn[2]++;
                    ans+=p[i][2];
                }
            }
        }
        if(cn[0]>n/2)
        {
            for(int i=1;i<=n;i++)
            {
                if(p[i][0]>=p[i][1]&&p[i][0]>=p[i][2])
                    q[++m]=min(p[i][0]-p[i][1],p[i][0]-p[i][2]);
            }
            sort(q+1,q+m+1);
            for(int i=1;i<=cn[0]-n/2;i++)
            {
                ans-=q[i];
            }
        }
        if(cn[1]>n/2)
        {
            for(int i=1;i<=n;i++)
            {
                if(p[i][1]>=p[i][0]&&p[i][1]>=p[i][2])
                    q[++m]=min(p[i][1]-p[i][0],p[i][1]-p[i][2]);
            }
            sort(q+1,q+m+1);
            for(int i=1;i<=cn[1]-n/2;i++)
            {
                ans-=q[i];
            }
        }
        if(cn[2]>n/2)
        {
            for(int i=1;i<=n;i++)
            {
                if(p[i][2]>=p[i][1]&&p[i][2]>=p[i][0])
                    q[++m]=min(p[i][2]-p[i][1],p[i][2]-p[i][0]);
            }
            sort(q+1,q+m+1);
            for(int i=1;i<=cn[2]-n/2;i++)
            {
                ans-=q[i];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
