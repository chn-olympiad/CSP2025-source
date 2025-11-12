#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int book[10000][10050];
int w[10050][10050];
int wi[10050][10050];
int cw[15];
int z[10000];
int b[10000];
int minl=999999;
bool cmp(int a,int b)
{
    return a>b;
}
void dfs(int a,int zon,int shu)
{
    if(shu==m)
    {
        minl=min(zon,minl);
        return;
    }
    for(int i=1; i<=m; i++)
    {
        if(book[a][i]==1||book[i][a]==1)
        {
            continue;
        }
        if(b[w[a][i]]==1)
        {

            w[a][i]=0;
            w[i][a]=0;
        }
        book[a][i]==1;
        book[i][a]==1;
        dfs(i,zon+w[a][i],shu+1);
        book[a][i]==0;
        book[i][a]==0;
    }
}
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);


    cin>>n>>m>>k;

    for(int i=1,a,b; i<=m; i++)
    {
        cin>>a>>b;
        cin>>w[a][b];
        z[i]=w[a][b];
        w[b][a]=w[a][b];
    }
    for(int i=1,a,b; i<=k; i++)
    {
        cin>>cw[i];
        for(int j=1; j<=n; j++)
        {
            cin>>wi[i][j];
        }
    }
    sort(z+1,z+n+1,cmp);
    for(int i=1; i<=k; i++)
    {
        b[z[i]]++;
    }
    dfs(1,0,0);
    cout<<minl;
    return 0;
}
