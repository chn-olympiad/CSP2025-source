#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
        freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int w[n+1][n+1]={0};
    for(int i=0;i<m;i++){
        int t1,t2;
        cin>>t1>>t2;
        if(t1>t2) swap(t1,t2);
        cin>>w[t1][t2];
    }
    for(int i=0;i<k;i++)
    {
        int c,wt[n+1];
        cin>>c;
        for(int j=1;j<=n;j++) cin>>wt[j];
        for(int j=1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                if(w[j][k]==0)w[k][j]=w[j][k]=c+wt[j]+wt[k];
                else w[k][j]=w[j][k]=min(w[j][k],c+wt[j]+wt[k]);
            }
        }
    }
    int summmmm=0;
    for(int i=1;i<=n;i++) w[i][i]=INT_MAX;
    for(int i=1;i<n;i++){
            int minn=INT_MAX;
        for(int j=1;j<=n;j++){
            minn=min(minn,w[i][j]);
        }
        summmmm+=minn;
    }
    cout<<summmmm;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
