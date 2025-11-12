#include  <bits/stdc++.h>
using namespace std;
int n,m,a[200],s,e;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    s=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==s)
        {
            e=i;
            break;
        }
        // cout<<a[i]<<" ";
    }
    // cout<<endl;
    if(e%n==0)
    {
        int x=e/n;
        if(x%2==0)
            cout<<x<<" "<<1;
        else
            cout<<x<<" "<<n;
    }
    else
    {
        int x=(e/n)+1,y=e%n;
        if(x%2==0)
            cout<<x<<" "<<n-y+1;
        else
            cout<<x<<" "<<y;
    }
    return 0;
}
/*

3 3
94 95 96 97 98 99 100 93 92

*/
/*
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
freopen
zhu yi hang shu*/