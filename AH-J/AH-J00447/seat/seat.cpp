#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x,y,s1;
    cin>>n>>m;
    int s=n*m;
    int a[102];
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int a1=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==a1){
            s1=n*m+1-i;
            break;
        }

    }
    x=(s1+n-1)/n;

    if(x%2==1)
    {
        if(s1%n==0) y=n;
        else y=s1%n;}
    else if(x%2==0)
    {
        if(s1%n==0) y=1;
        else y=n+1-s1%n;
    }
    cout<<x<<' '<<y;
    return 0;
}
