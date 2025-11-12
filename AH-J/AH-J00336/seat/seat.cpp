#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[105];
    int n,m,k=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int s=a[1];
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--)
    {
        k+=1;
        if(a[i]==s)
        {
            break;
        }
    }
    int x,y;
    x=(k-1)/n+1;
    if(x%2==1)
    {
        y=k%n;
        if(y==0)
        {
            y=n;
        }
    }
    else
    {
        y=n-(k%n)+1;
        if(k%n==0);
        {
            y=1;
        }
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}
