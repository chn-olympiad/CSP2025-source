#include <bits/stdc++.h>
using namespace std;
int a[100015][5];
int b[100015][5];
int vis[100015];
int sum;
int aa,bb,cc;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for (int i = 1;i <= n;i++)
        {
            scanf("%d",&a[i][1]);
            scanf("%d",&a[i][2]);
            scanf("%d",&a[i][3]);
            b[i][1] = a[i][1];
            b[i][2] = a[i][2];
            b[i][3] = a[i][3];
        }
        for (int i = 1;i <= n;i++)
        {
            if (a[i][1]<a[i+1][1])
            {
                vis[b[i][1]] = i;
                vis[b[i+1][1]] = i;
                b[i][1] = a[i+1][1];
                b[i+1][1] = a[i][1];
            }
        }
        for(int i = 1;i <= n;i++)
        {
            int sz = max(b[i][1],b[vis[b[i][1]]][2]);
            sz = max(sz,b[vis[b[i][1]]][3]);
            if (sz == b[i][1])
            {
                if(aa<=(n/2))
                {
                    sum+=max(b[vis[b[i][1]]][2],b[vis[b[i][1]]][3]);
                    if (b[vis[b[i][1]]][2]>b[vis[b[i][1]]][3])
                    {
                        bb++;
                    }
                    else
                    {
                        cc++;
                    }
                }
                else
                {
                    sum+=b[i][1];
                    aa++;
                }

            }
            else if(sz == b[vis[b[i][1]]][2])
            {
                if(bb<=(n/2))
                {
                    sum+=max(b[i][1],b[vis[b[i][1]]][3]);
                    if (b[i][1]>b[vis[b[i][1]]][3])
                    {
                        aa++;
                    }
                    else
                    {
                        cc++;
                    }
                }
                else
                {
                    sum+=b[vis[b[i][1]]][2];
                    bb++;
                }

            }
            else if(sz == b[vis[b[i][1]]][3])
            {
                if(cc<=(n/2))
                {
                    sum+=max(b[i][1],b[vis[b[i][1]]][2]);
                    if (b[i][1]>b[vis[b[i][1]]][2])
                    {
                        aa++;
                    }
                    else
                    {
                        bb++;
                    }
                }
                else
                {
                    sum+=b[vis[b[i][1]]][2];
                    cc++;
                }
            }

        }
        printf("%d",sum);
    }
    return 0;
}
