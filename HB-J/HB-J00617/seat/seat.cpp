#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int a[1100];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int t=n*m;
    cin>>a[1];
    int R=a[1];
    int xR;
    for(int i=2;i<=t;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+t+1);
    for(int i=1;i<=t;i++)
    {
        if(a[i]==R)
        {

            xR=i;
            break;
        }
    }
    int w=xR%n;
    int q=xR/n;

    if(w==0)
    {
        c=q;
    }
    else{
        c=q+1;
    }
    if(c%2==0)
    {
        r=n-w+1;
    }
    else{
        r=w;
    }
    cout<<c<<" "<<r;
    return 0;
}
