#include<bits/stdc++.h>
using namespace std;
int n,m,flag=1,x=1,y=1;
int a[111];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int z=n*m;
    cin>>a[1];
    for(int i=2;i<=z;i++)
    {
        cin>>a[i];
        if(a[i]>a[1])
        {
            flag++;
        }
    }
    while(flag>n)
    {
        flag=flag-n;
        x++;
    }
    if(x%2==0)
    {
        y=n-flag+1;
    }
    else if(x%2==1)
    {
        y=flag;
    }
    cout<<x<<" "<<y;
    return 0;
}
