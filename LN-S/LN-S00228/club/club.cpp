#include<bits/stdc++.h>
using namespace std;
long long n,a[20005][3]/*,b[100005][3],c[100005],sum[10]*/,mx[100005];
int t;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        cin >> n;
        for(int j=1;j<=n;j++)
        {
            cin >> a[j][1] >> a[j][2] >> a[j][3];
            mx[i]=max(a[j][1],mx[i]);
        }
        /*for(int j=1;j<=n;j++)
        {
            if(a[j][1]>=a[j+1][1])
            {
                b[j][1]=a[j][1];
                b[j+1][1]=0;
                if(a[j][2]>=a[j+1][2])
                {
                    b[j][2]=a[j][2];
                    b[j+1][2]=0;
                    if(a[j][3]>=a[j+1][3])
                    {
                        b[j][3]=a[j][3];
                        b[j+1][3]=0;
                    }
                    else
                    {
                        b[j][3]=0;
                        b[j+1][3]=a[j+1][3];
                    }
                }
                else
                {
                    b[j][2]=0;
                    b[j+1][2]=a[j+1][2];
                    if(a[j][3]>=a[j+1][3])
                    {
                        b[j][3]=a[j][3];
                        b[j+1][3]=0;
                    }
                    else
                    {
                        b[j][3]=0;
                        b[j+1][3]=a[j+1][3];
                    }
                }
            }
            else
            {
                b[j][1]=0;
                b[j+1][1]=a[j+1][1];
                if(a[j][2]>=a[j+1][2])
                {
                    b[j][2]=a[j][2];
                    b[j+1][2]=0;
                    if(a[j][3]>=a[j+1][3])
                    {
                        b[j][3]=a[j][3];
                        b[j+1][3]=0;
                    }
                    else
                    {
                        b[j][3]=0;
                        b[j+1][3]=a[j+1][3];
                    }
                }
                else
                {
                    b[j][2]=0;
                    b[j+1][2]=a[j+1][2];
                    if(a[j][3]>=a[j+1][3])
                    {
                        b[j][3]=a[j][3];
                        b[j+1][3]=0;
                    }
                    else
                    {
                        b[j][3]=0;
                        b[j+1][3]=a[j+1][3];
                    }
                }
            }
            c[j]=max(b[j][1],b[j][2]);
            c[j]=max(c[j],b[j][3]);
            sum[i]+=c[j];
        }*/
        cout << mx[i] << endl;
    }
    return 0;
}
