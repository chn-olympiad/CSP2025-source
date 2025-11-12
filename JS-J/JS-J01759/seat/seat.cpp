#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int x=a[1],s;
    sort(a+1,a+1+n*m,greater<int>());
    for(int i=m*n;i>=1;i--)
    {
        if(a[i]==x)
        {
            s=i;
        }
    }
    int c,r;
    if(s%n==0)
    {
        c=s/n;
    }else{
        c=s/n+1;
    }
    if(c%2==1)
    {
        if(s%n==0)
        {
            r=n;
        }else{
            r=s%n;
        }
    }else{
        if(s%n==0)
        {
            r=1;
        }else{
            r=n+1-s%n;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
