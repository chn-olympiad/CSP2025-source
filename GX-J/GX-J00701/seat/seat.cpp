#include<iostream>
#include<algorithm>
using namespace std;
int n,m,as[120],as2[120],seat[20][20],temp;
void mysort(int x,int y)
{
    seat[y][x]=as2[temp];
    temp--;
    if(temp<0)return;
    if(x%2!=0)
    {
        if(y<n)
        {
            return mysort(x,y+1);
        }
        else if(y==n)
        {
            return mysort(x+1,y);
        }
    }
    else
    {
        if(y>1)
        {
            return mysort(x,y-1);
        }
        else if(y==1)
        {
            return mysort(x+1,y);
        }
    }
}
void myfind()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(seat[i][j]==as[0])
            {
                cout<<j<<" "<<i;
                return;
            }
        }
    }
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
    {
        cin>>as[i];
        as2[i]=as[i];
    }
    sort(as2,as2+(n*m));
    temp=n*m-1;
    mysort(1,1);
    myfind();
    return 0;
}
