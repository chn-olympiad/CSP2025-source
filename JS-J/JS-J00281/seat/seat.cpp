#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m,t,w;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    t=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==t)
        {
            w=n*m-i+1;
        }
    }
    if(w%n==0)
    {
        cout<<w/n<<' ';
        if((w/n)%2==0)
        {
            cout<<1;
        }
        else
        {
            cout<<n;
        }
    }
    else
    {
        cout<<w/n+1<<' ';
        if((w/n+1)%2==0)
        {
            cout<<n-w%n+1;
        }
        else
        {
            cout<<w%n;
        }
    }
    return 0;
}
