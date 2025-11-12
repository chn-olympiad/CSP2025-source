#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[105],x,y;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        k=a[1];
    }
    sort(a+1,a+n*m+1,greater<long long>());
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==k)
        {
            k=i;
            break;
        }
    }
    k--;
    y=(k/n)+1;
    if(y%2==1)
    {
        x=(k%n)+1;
    }
    else
    {
        x=n-(k%n);
    }
    cout<<y<<" "<<x;
    return 0;
}
