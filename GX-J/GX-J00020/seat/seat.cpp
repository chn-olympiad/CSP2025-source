#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[102],b,c,k=1,d,s;
    cin>>b;
    for(int i=2;i<=n*m;i++)
    {
        cin>>c;
        if(c>b)
        {
            k++;
        }

    }
    d=k/n+1;
    if(d%2==0)
    {
        s=n-(k%n-1);
    }
    else
    {
        s=k%n;
    }
    cout<<d<<" "<<s;
    return 0;
}
