#include<bits/stdc++.h>
using namespace std;
int m,n,cj[110],dis=1,x=1,y=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=m*n; i++)
    {
        cin>>cj[i];
    }
    int R=cj[1];
    sort(cj+1,cj+n*m+1);
    int j=m*n;
    while(cj[j]!=R)
    {
        if(dis==1)
        {
            y++;
            if(y+1>m)
            {
                dis=2;
            }
        }
        else if(dis==2)
        {
            x++;
            if(y+1>m)
            {
                dis=3;
            }
            else if(y-1<1)
            {
                dis=1;
            }
        }
        else
        {
            y--;
            if(y-1<1)
            {
                dis=2;
            }
        }
        j--;
    }
    cout<<x<<' '<<y;
    return 0;
}
