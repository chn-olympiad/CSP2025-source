#include<bits/stdc++.h>
using namespace std;
int n,m,x,s,xx,yy;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>x;
    for(int i=2;i<=n*m;i++)
    {
        int y;
        cin>>y;
        if(y>x)
          s++;
    }
    xx=s/n+1;
    if(xx%2==0)
    {
       yy=n-s%n;
    }
    else
    {
        yy=s%n+1;
    }
    cout<<xx<<" "<<yy;
    return 0;
}
