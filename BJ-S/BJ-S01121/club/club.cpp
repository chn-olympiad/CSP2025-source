#include<bits/stdc++.h>

using namespace std;
int n;
struct node
{
    int num,y;
}a[100010][4];
bool cmp(node a,node b)
{
    return a.num>b.num;
}
struct node2
{
    int num,c;
}d[4][100010];
bool cmp2(node2 a,node2 b)
{
    return a.c>b.c;
}
int cur[4];

int chan[100010];
int k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        k=0;
        memset(cur,0,sizeof(cur));
        memset(d,0,sizeof(d));
        memset(chan,0,sizeof(chan));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j].num;
                a[i][j].y=j;
            }
            sort(a[i]+1,a[i]+3+1,cmp);
            chan[i]=a[i][1].num-a[i][2].num;

            d[a[i][1].y][++cur[a[i][1].y]]={a[i][1].num,chan[i]};
        }

        for(int i=1;i<=3;i++)
        {
            //cout<<cur[i]<<endl;
            if(cur[i]>(n/2))
            {
                k=i;
            }
        }
        if(k==0)
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {

                ans+=a[i][1].num;
            }
            cout<<ans<<endl;
        }
        else
        {
            sort(d[k]+1,d[k]+n+1,cmp2);
            int ans=0;
            for(int i=1;i<=n;i++)
            {

                ans+=a[i][1].num;
            }
            for(int i=(n/2)+1;i<=cur[k];i++)
            {
                ans-=d[k][i].c;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
