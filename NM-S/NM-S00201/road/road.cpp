#include <bits/stdc++.h>
using namespace std;
int b[1001]={0};int num=0;
int print(int mun)
{
    minj=min(minj,num);
}
void search(int u[],int v[],int w[],int i,int )
{
    if(!b[i])
    {
        
        b[i]=1;
        j+=u[i];
        j+=v[i];
        num+=w[i];
        if(u[i]+v[i]==mun)print(num);
        else search(u,v,w,i+2);
        j-=u[i];
        j-=v[i];
        b[i]=0;
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int t;
    int n,k,m;
    cin>>n>>k>>m;
    int u[m+1] ,v[m+1],w[m+1];
    int c[k],a[k][n];
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int j=1;j<=k;j++)
    {
        cin>>c[k];
        for(int i=1;i<=n;i++)
        {
            cin>>a[j][i];
        }
    }
    for(int i=1;i<=n;i++)mun+=i;
     search(u,v,w,0)
     cout<<minj;
     return 0;
}

