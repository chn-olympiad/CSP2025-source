#include <bits/stdc++.h>
using namespace std;
int a,n,m,num=1,s;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a;
    for(int i=1;i<=n*m-1;i++)
    {
        cin>>s;
        if(s>a)
            num++;
    }
    if(num%n!=0)
    {
        int c=int(num/n)+1;
        int b=c*n-num;
        cout<<c<<' ';
        if(c%2==0)
            cout<<b+1;
        else
            cout<<n-b;
    }
    else
    {
        int c=num/n;
        cout<<c<<' ';
        if(c%2==0)
            cout<<1;
        else
            cout<<n;
    }
    return 0;
}
