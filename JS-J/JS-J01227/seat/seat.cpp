#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int s=n*m;
    for(int i=1;i<=s;i++)
    {
        cin>>a[i];
    }
    t=a[1];
    sort(a+1,a+s+1);
    reverse(a+1,a+s+1);
    int x;
    for(int i=1;i<=s;i++)
    {
        if(a[i]==t)
        {
            x=i;
            break;
        }
    }
    int p=x/n,q=x%n;
    if(p%2==1)
    {
        if(q==0)
        {
            cout<<p<<" "<<n;
        }
        else
        {
            cout<<p+1<<" "<<n-q+1;
        }
    }
    else
    {
        if(q==0)
        {
            cout<<p<<" "<<1;
        }
        else
        {
            cout<<p+1<<" "<<q;
        }
    }
    return 0;
}
