#include <bits/stdc++.h>
using namespace std;
const int N=1e4+100,MAXN=1e9+9;
long long node[N][N];
int c[15];
bool route[N];
int n,m,k;
long long cnt=0;
bool flag()
{
    for(int i=1;i<=k;i++){
        if(c[i]!=0)return false;
    }
    return true;
}
long long fd(int x)
{
    long long minn=MAXN,idx=0;

    if(x<=n){
    cnt++;
    //cout<<x<<" ";
    if(cnt>=n)return 0;


    for(int i=1;i<=n;i++)
    {
        if(route[i]||node[x][i]==-1)continue;
        if(node[x][i]<minn){
            idx=i;
            minn=node[x][i];
        }
    }

    for(int i=n+1;i<=n+k;i++)
    {
        if(route[i]||node[x][i]==-1)continue;
        if(node[x][i]+c[i-n]/2<minn)
        {
            idx=i;
            minn=node[x][i];
        }
    }
    route[idx]=true;
    //cout<<minn<<" ";
    return minn+fd(idx);
    }
    if(x>n)
    {
        //cout<<x<<" ";
        for(int i=1;i<=n;i++)
        {
            if(route[i]||node[x][i]==-1)continue;
            if(node[x][i]<minn){
            idx=i;
            minn=node[x][i];
            }
        }
        route[idx]=true;
        //cout<<minn<<" ";
        return minn+(c[x-n]-c[x-n]/2)+fd(idx);
    }
}
long long fd2(int x)
{
    long long minn=MAXN,idx=0;

    if(x<=n){
    cnt++;
    if(cnt>=n)return 0;
    //cout<<x<<" ";

    for(int i=1;i<=n;i++)
    {
        if(route[i]||node[x][i]==-1)continue;
        if(node[x][i]<minn){
            idx=i;
            minn=node[x][i];
        }
    }

    for(int i=n+1;i<=n+k;i++)
    {
        if(route[i]||node[x][i]==-1)continue;
        if(node[x][i]<minn)
        {
            idx=i;
            minn=node[x][i];
        }
    }
    route[idx]=true;
    //cout<<minn<<" ";
    return minn+fd(idx);
    }
    if(x>n)
    {
        //cout<<x<<" ";
        for(int i=1;i<=n;i++)
        {
            if(route[i]||node[x][i]==-1)continue;
            if(node[x][i]<minn){
            idx=i;
            minn=node[x][i];
            }
        }
        route[idx]=true;
        //cout<<minn<<" ";
        return minn+fd(idx);
    }
}
int main()
{

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        route[i]=false;
        for(int j=1;j<=n;j++)node[i][j]=-1;
    }
    for(int i=1;i<=m;i++)
    {
        int l,r,w;
        cin>>l>>r>>w;
        node[l][r]=w;
        node[r][l]=w;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>node[n+i][j];
            node[j][n+i]=node[n+i][j];
        }
    }
    int idx=1;
    long long maxx=1000*MAXN;
    for(int i=1;i<=n;i++)
    {
        long long sum=0;
        for(int j=1;j<=n;j++)sum+=node[i][j];
        if(sum<maxx)idx=i;
    }
    if(flag()){
        route[idx]=true;
        cout<<fd2(idx);
    }
    else{
    route[idx]=true;
    cout<<fd(idx);
    }
}
