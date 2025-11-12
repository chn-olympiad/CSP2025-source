#include<bits/stdc++.h>
using namespace std;
int r[105];
bool R(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopwn("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>r[i];
    int k=r[1];
    sort(r+1,r+n*m+1,R);
    int x=1,y=1,t=1;
    for(int i=1;r[i]!=k;i++)
    {
        if(y==n&&x%2==1 || y==1&&x%2==0)
        {
            x++;
            t*=-1;
        }
        else
            y+=t;
    }
    cout<<x<<' '<<y;
    return 0;
}
