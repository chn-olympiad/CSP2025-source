#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int n,m;
int x=1,y=1;
int cnt=1;
bool visit[11][11]={false};
struct node
{
    int nx,ny,pro;
}c[101];
bool cmp(node x,node y)
{
    return x.pro>y.pro;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++)
    {
        cin>>c[i].pro;
    }
    node tag=c[1];
    sort(c+1,c+(m*n)+1,cmp);
    while(cnt<=m*n)
    {
        a[x][y]=c[cnt].pro;
        c[cnt].nx=x;
        c[cnt].ny=y;
        cnt+=1;

        if(x==n&&visit[x][y]==false)
        {
            y+=1;
            visit[x][y]=true;
            x+=1;
        }
        if(y%2!=1&&x!=1)
        {
            x-=1;
        }
        else if(x==1&&y%2==0&&visit[x][y]==false)
        {
            y+=1;
            visit[x][y]=true;
            x-=1;
        }
        if(y%2==1)
        {
            x+=1;
        }

    //cout<<a[x][y]<<" ";
    }

    for(int i=1;i<=m*n;i++)
    {
        if(c[i].pro==tag.pro)
        {
            tag.nx=c[i].nx;
            tag.ny=c[i].ny;
        }
    }
    cout<<tag.ny<<" "<<tag.nx;
    return 0;
}
