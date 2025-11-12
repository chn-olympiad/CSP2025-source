#include<bits/stdc++.h>//Ren5Jie4Di4Ling5%
using namespace std;

long long n,m,k,ans,F;
int a[1010][1010],maxxx,A=0x3f3f3f3f;

int b[10];int c[10][1010];

int d[1010];

bool e[1010];


void dfs(int x,int id)
{
    if(x==n-1||F==1)
    {
        F=1;
        return;
    }
    int minn=0x3f3f3f,idd;
    for(int i=1;i<n;i++)
    {
        if(e[i]==0)
        {
            d[i]=min(d[i],a[id][i]);
            if(d[i]<minn)
            {
                minn=d[i];
                idd=i;
            }
        }
    }
    ans+=minn;
    e[idd]=1;
    //cout<<idd+1;
    dfs(x+1,idd);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    //if(A)----
    scanf("%d%d%d",&n,&m,&k);
    int x,y,z;
    memset(a,0x3f3f3f,sizeof(a));
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        a[x-1][y-1]=min(a[x-1][y-1],z);
        a[y-1][x-1]=a[x-1][y-1];
    }
/*    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<' ';
        }cout<<endl;
    }*/
    for(int i=0;i<k;i++)
    {
        scanf("%d",&b[i]);
        int id=-1;
        for(int j=0;j<n;j++)
        {
            scanf("%d",&c[i][j]);
            if(c[i][j]==0)
                id=j;
        }
        if(id!=-1)
        {
            for(int j=0;j<n;j++)
            {
                a[j][id]=a[id][j]=min(a[id][j], c[i][j]+b[i]);
            }
        }
    }

    e[0]=1;
    memset(d,0x3f3f3f,sizeof(d));
    dfs(0,0);
    cout<<ans;
    return 0;
}
