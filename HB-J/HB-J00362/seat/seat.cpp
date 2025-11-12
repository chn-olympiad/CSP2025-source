#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int i;
    int anan=n*m;
    int x;
    int y;
    cin>>x;
    int num=1;
    for(i=2;i<=anan;i++)
    {
        cin>>y;
        if(y>x)
            num++;
    }
    int b1,b2;
    b1=num/n;
    b2=num%n;
    if(b2==0)
    {
        b2=n;
    }
    else
    {
        b1++;
    }
    if(b1%2==0)
    {
        b2=n-b2+1;
    }
    cout<<b1<<" "<<b2<<endl;
    return 0;
}
