#include<bits/stdc++.h>
using namespace std;
int a[1010],t,h,x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>n>>m;
    for(int i=1;i<=m*n;i++)
    cin>>a[i];
    t=a[1];
    sort(a+1,a+1+m*n);
    for(int i=1;i<=m*n;i++)
    {
        if(a[i]==t)
        h=m*n-i+1;
    }
    if(h%n==0)
    x=h/n;
    else
    x=h/n+1;
    if(x%2==1&&h%n!=0)
    {
        y=h%n;
    }
    if(x%2==1&&h%n==0)
    {
        y=n;
    }
    if(x%2==0&&h%n!=0)
    {
        y=n+1-h%n;
    }
    if(x%2==0&&h%n==0)
    {
        y=1;
    }
    cout<<x<<" "<<y;
    return 0;
}
