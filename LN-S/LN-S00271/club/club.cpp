#include<bits/stdc++.h>
using namespace std;
int a[100005], b[100005], c[100005], v[100005][4], n,z[100005][4],ft[100005];
struct node
{
    int num;
    int q;
}d[3*100005];
bool cmp(node a, node b)
{
    return a.q>b.q;
}
bool cmp1(int a, int b)
{
    return a>b;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int ll = 1;
        scanf("%d", &n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
        }
        for(int i=1;i<=n;i++)
        {
            int maxx = a[i], f = 1;
            if(b[i]>maxx)
            {
                maxx = b[i];
                f=2;
            }
            if(c[i]>maxx)
            {
                maxx = c[i];
                f=3;
            }
            if(f ==1)
            {
                v[i][1] = 0;
                v[i][2] = b[i]-a[i];
                v[i][3] = c[i]-a[i];
                z[i][1] = 1;
            }
            if(f ==2)
            {
                v[i][1] = a[i]-b[i];
                v[i][2] = 0;
                v[i][3] = c[i]-b[i];
                z[i][2] = 1;
            }
            if(f ==3)
            {
                v[i][1] = a[i]-c[i];
                v[i][2] = b[i]-c[i];
                v[i][3] = 0;
                z[i][3] = 1;
            }
        }
        for(int i=1;i<=n;i++)
        {
            d[i].num = i;
            d[i].q = v[i][1];
            d[n+i].num = i;
            d[n+i].q = v[i][2];
            d[2*n+i].num = i;
            d[2*n+i].q = v[i][3];
        }
        sort(d+1, d+3*n+1,cmp);
        int ax=0, bx=0, cx=0;
        for(int i=1;i<=n;i++)
        {
            if(z[i][1]==1)
            {
                ax++;
            }
            if(z[i][2]==1)
            {
                bx++;
            }
            if(z[i][3]==1)
            {
                cx++;
            }
        }
        if(ax>n/2)
        {
            int al = ax-n/2;
            for(int i=n+1;i<=3*n;i++)
            {
                if(v[d[i].num][1]==0&&ft[d[i].num]==0)
                {
                    if(v[d[i].num][2]==d[i].q)
                    {
                        z[d[i].num][1]=0;
                        z[d[i].num][2]=1;
                        z[d[i].num][3]=0;
                    }
                    else
                    {
                        z[d[i].num][1]=0;
                        z[d[i].num][2]=0;
                        z[d[i].num][3]=1;
                    }
                    ft[d[i].num]=1;
                    al--;
                }
                if(al==0)
                {
                    break;
                }
            }
        }
        else if(bx>n/2)
        {
            int bl = bx-n/2;
            for(int i=n+1;i<=3*n;i++)
            {
                if(v[d[i].num][2]==0&&ft[d[i].num]==0)
                {
                    if(v[d[i].num][1]==d[i].q)
                    {
                        z[d[i].num][1]=1;
                        z[d[i].num][2]=0;
                        z[d[i].num][3]=0;
                    }
                    else
                    {
                        z[d[i].num][1]=0;
                        z[d[i].num][2]=0;
                        z[d[i].num][3]=1;
                    }
                    ft[d[i].num]=1;
                    bl--;
                }
                if(bl==0)
                {
                    break;
                }
            }
        }
        else if(cx>n/2)
        {
            int cl = cx-n/2;
            for(int i=n+1;i<=3*n;i++)
            {
                if(v[d[i].num][3]==0&&ft[d[i].num]==0)
                {
                    if(v[d[i].num][1]==d[i].q)
                    {
                        z[d[i].num][1]=1;
                        z[d[i].num][2]=0;
                        z[d[i].num][3]=0;
                    }
                    else
                    {
                        z[d[i].num][1]=0;
                        z[d[i].num][2]=1;
                        z[d[i].num][3]=0;
                    }
                    ft[d[i].num]=1;
                    cl--;
                }
                if(cl==0)
                {
                    break;
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            if(z[i][1]==1)
            {
                ans+=a[i];
            }
            else if(z[i][2]==1)
            {
                ans+=b[i];
            }
            else
            {
                ans+=c[i];
            }
        }
        cout<<ans<<"\n";
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                v[i][j]=0;
                ft[i]=0;
                z[i][j]=0;
            }
        }
    }
    return 0;
}
