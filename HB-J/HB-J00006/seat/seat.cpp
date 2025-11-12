#include<bits/stdc++.h>
using namespace std;
bool cmp(int _a,int _b)
{
    if(_a>_b)
        return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>n>>m;
    short a[114];
    int r;
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
        if(i==0)
            r=a[i];
    }
    sort(a,a+m*n,cmp);
    int l=0;
    for(int i=0;i<n*m;i++)
    {
        if(a[i]==r)
            l=i+1;
    }
    int x=floor(l/n);
    int y=l%n;
    if(l%n!=0)
        x++;
    if(x%2!=0)
    {
        if(y==0)
            y=n;
    }
    else
    {
        if(y==1)
            y=n;
        else if(y==0)
            y=1;
        else
            y=n-y+1;
    }
    cout<<x<<' '<<y;
    return 0;
}
