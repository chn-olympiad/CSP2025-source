#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int a1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int w=n*m;
    for(int i=1;i<=w;i++)
    {
        cin>>a[i];
    }
    a1=a[1];
    int z;
    sort(a,a+w+1);
    int s=0;
    for(int i=w;i>=1;i--)
    {
        s++;
        if(a1==a[i])
        {
            z=s;
        }
    }
    int x,y;
    x=ceil(z*1.0/n);
    if(x%2==0)
    {
        y=n-(z-n*(x-1))+1;
    }
    else
    {
        y=z-n*(x-1);
    }
    cout<<x<<" "<<y;
    return 0;
}
