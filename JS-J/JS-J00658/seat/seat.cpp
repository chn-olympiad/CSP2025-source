#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(a[i]>=a[1])
        {
            cnt++;
        }
    }
    int c,r=0;
    if(cnt%n==0)
    {
        c=cnt/n;
        if(c%2==1)
        {
            r=n;
        }
        else
        {
            r=1;
        }
        cout<<c<<" "<<r<<endl;
        return 0;
    }
    else
    {
        c=cnt/n+1;
        if(c%2==1)
        {
            r=cnt%n;
        }
        else
        {
            r=n-cnt%n+1;
        }
        cout<<c<<" "<<r<<endl;
        return 0;
    }
}
