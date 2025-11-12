#include <bits/stdc++.h>
using namespace std;
int a[15][15]={0},b[105]={0};
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>b[i];
    }
    int q=b[1];
    sort(b+1,b+n*m+1);
    int x=1,y=0;
    bool d=0;//0 down 1 up
    for(int i=n*m;i>=1;i--)
    {
        if(d==0)
        {
            y++;
            if(y>n)
            {
                d=1;
                x++;
                y--;
            }
        }
        else
        {
            y--;
            if(y<1)
            {
                d=0;
                x++;
                y++;
            }
        }
        a[x][y]=b[i];
        if(a[x][y]==q)
        {
            cout<<x<<" "<<y;
            break;
        }
    }
    return 0;
}//Score++100 Score--70
