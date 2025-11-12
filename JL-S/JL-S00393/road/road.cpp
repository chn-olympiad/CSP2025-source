#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1000000][4];//lu
int b[15][10010];//xz
int bb[15];
int x[10010]={0};
int aaa(int xx,int kk)
{
    int mm=9999999;
    for(int i=1;i<=n;i++)
        if(b[kk][i]<mm&&i!=xx)
            mm=b[kk][i];
    return b[kk][xx]+b[kk][0]+mm;
}
int dfs()
{
    for(int i=1;i<=k;i++)
        if(bb[i]!=-1)
            bb[i]=b[i][0];
    int inbb=0,inbbi=0;
    for(int j=1;j<=k;j++)
    {
        if(bb[k]!=-1)
        for(int i=1;i<=m;i++)
            if(a[i][0]==1)
            {
                if(a[i][3]>b[k][a[i][1]]+b[k][a[i][2]])
                    bb[k]=bb[k]-a[i][3]+b[k][a[i][1]]+b[k][a[i][2]];
            }
    }
    for(int i=1;i<=k;i++)
        if(inbb>bb[i])
        {
            inbbi=i;
            inbb=bb[i];
        }
    return inbbi;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>a[i][1]>>a[i][2]>>a[i][3];
    for(int j=1;j<=k;j++)
        for(int i=0;i<=n;i++)
            cin>>b[k][i];
    for(int j=1;j<=m;j++)
        for(int i=1;i<m;i++)
            if(a[i][3]>a[i+1][3])
            {
                int t;
                t=a[i][1];
                a[i][1]=a[i+1][1];
                a[i+1][1]=t;
                t=a[i][2];
                a[i][2]=a[i+1][2];
                a[i+1][2]=t;
                t=a[i][3];
                a[i][3]=a[i+1][3];
                a[i+1][3]=t;
            }
    int fy=0;
    for(int i=1;i<=m;i++)
    {
        if(x[a[i][1]]==0||x[a[i][2]]==0)
        {
            x[a[i][1]]=1;
            x[a[i][2]]=1;
            a[i][0]=1;
            fy+=a[i][3];
        }
    }
    for(int i=1;i<=k;i++)
        bb[i]=b[i][0];
    /*for(int j=1;j<=k;j++)
    {
        for(int i=1;i<=m;i++)
            if(a[i][0]==1)
            {
                if(a[i][3]>b[k][a[i][1]]+b[k][a[i][2]])
                    bb[k]=bb[k]-a[i][3]+b[k][a[i][1]]+b[k][a[i][2]];
            }
    }*/
    int aa=dfs();
    while(aa!=0)
    {

        if(bb[k]<0)
        {
            fy+=b[k][0];
            bb[k]=-1;
            for(int i=1;i<=m;i++)
                if(a[i][0]==1)
                {
                    if(a[i][3]>b[k][a[i][1]]+b[k][a[i][2]])
                    {
                        fy=fy-a[i][3]+b[k][a[i][1]]+b[k][a[i][2]];
                        a[i][0]=0;
                    }
                }
        }
        aa=dfs();
    }
    cout<<fy<<endl;
    return 0;
}
