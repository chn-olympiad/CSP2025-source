#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,a[100010][5];
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int maxn=-1,maxp=0;
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
                if(a[i][j]>maxn)
                {
                    maxn=a[i][j];
                    maxp=j;
                }
            }
            a[i][4]=maxn;
            a[i][5]=maxp;
        }
        int x=0,y=0,z=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i][5]==1)
            {
                if(x<n/2)
                {
                    ans+=a[i][1];
                    x++;
                }
                else
                {
                    if(a[i][2]>a[i][3]&&y<n/2)
                    {
                        ans+=a[i][2];
                        y++;
                    }
                    else
                    {
                        ans+=a[i][3];
                        z++;
                    }
                }
            }
            else if(a[i][5]==2)
            {
                if(y<n/2)
                {
                    ans+=a[i][2];
                    y++;
                }
                else
                {
                    if(a[i][1]>a[i][3]&&x<n/2)
                    {
                        ans+=a[i][1];
                        x++;
                    }
                    else
                    {
                        ans+=a[i][3];
                        z++;
                    }
                }
            }
            else
            {
                if(z<n/2)
                {
                    ans+=a[i][3];
                    z++;
                }
                else
                {
                    if(a[i][1]>a[i][2]&&x<n/2)
                    {
                        ans+=a[i][1];
                        x++;
                    }
                    else
                    {
                        ans+=a[i][2];
                        y++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
