#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,i,n,j,ans=0;
    int cinmax[3]={0,0,0};
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        int a[n][3];
        for(j=0;j<n;j++)
        {
            cin>>a[n][0]>>a[n][1]>>a[n][2];
            if(a[n][1]>a[n][2] || a[n][1]==a[n][2])
            {
                if(a[n][1]>a[n][3] || a[n][1]==a[n][3])
                {
                    if(cinmax[0]<=n/2)
                    {
                        cinmax[0]++;
                        ans+=a[n][0];
                    }
                    else
                    {
                        cinmax[2]++;
                        ans+=a[n][2];
                    }
                }
                else
                {
                    if(cinmax[2]<=n/2)
                    {
                        cinmax[2]++;
                        ans+=a[n][2];
                    }
                    else
                    {
                        cinmax[1]++;
                        ans+=a[n][1];
                    }
                }
            }
            else
            {
                if(cinmax[1]<=n/2)
                    {
                        cinmax[1]++;
                        ans+=a[n][1];
                    }
                    else
                    {
                        cinmax[0]++;
                        ans+=a[n][0];
                    }
            }
        }
        cout<<ans;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
