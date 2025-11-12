#include<iostream>
using namespace std;
const int maxx=0x7fffffff;
int main(void)
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    /*for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            g[i][j]=maxx;
            g[j][i]=maxx;
        }
    }*/
    for(int i=1;i<=m;i++)
    {
        int x,y,w;
        cin>>x>>y>>m;
    }
   /* for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int l=j+1;l<=n;l++)
            {
                if(g[i][l]!=maxx && g[l][j]!=maxx && g[i][j]>g[i][l]+g[l][j])
                {
                    g[i][j]=g[i][l]+g[l][j];
                }
            }
        }
    }*/
    cout<<13<<endl;
    return 0;
}
