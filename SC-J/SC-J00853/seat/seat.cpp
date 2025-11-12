#include <bits/c++std.h>

using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x;
    int l[n*m];
    cin>>n,m;
    cin>>l;
    for(i=1,i<=m*n,i++)
    {
        if(l[0]>l[i])
        {
            x++;
        }
    }
    if(x/(2*m)<=m)
    {
        cout<<(x+m-1)/m<<x-x/m*m;
    }
    else
    {
        cout<<m-((x+m-1)/m)+1<<x-x/m*m;
    }
    return 0;
}
