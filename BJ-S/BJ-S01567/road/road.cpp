#include <bits/stdc++.h>

using namespace std;
int n,m,k;
int a[10000][10000];
int coutry[1000];
bool visit[1000][1000];
int w;
int c[1000];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int v1,v2,w1;
        cin>>v1>>v2>>w1;
        a[v1][v2]=w1;
        a[v2][v1]=w1;
    }
    for(int i=1;i<=k;i++){
        cin>>c[k+i];
        for(int j=1;j<=n;j++){
            cin>>w;
            a[j][n+i]=w;
            a[n+i][j]=w;
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int minn=0x0f0f0f;
            for(int p=j+1;p<=n+k;p++){
                int summ=0;
                if(p<=n){
                    if(visit[i][p]!=0)
                        summ+=a[i][p];
                    if(visit[p][i]!=0)
                        summ+=a[p][i];
                }
                else{
                    if(visit[i][p]!=0)
                        summ+=a[i][p];
                    if(visit[p][i]!=0)
                        summ+=a[p][i];
                    summ+=c[p];
                }
                minn=min(minn,summ);
            }
            sum=sum+minn;
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
