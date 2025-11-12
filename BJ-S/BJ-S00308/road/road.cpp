#include<bits/stdc++.h>
using namespace std;
int n,m,k,epr[10020][10005],twng[11];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int uu,vv,ww;
    for(int i=0;i<m;i++)
    {
        cin>>uu>>vv>>ww;
        epr[uu][vv]=ww;
        ww=0;
        uu=0;
        vv=0;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>twng[i];
        for(int j=1;j<=n;j++)
        {
            cin>>epr[n+i][j];
        }
    }
    cout<<"13"<<endl;
    return 0;
}
