#include<bits/stdc++.h>
using namespace std;
long long a[15];
int main()
{
    
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,ans=1;
    cin>>n>>m;
    int k;
    cin>>k;
    for(int i=2;i<=n*m;i++)
    {
        int x;
        cin>>x;
        if(k<x)
        {
            ans++;
        }
    }
    int l=ans/n;
    if(ans%n!=0)
    {
        l++;
    }
    if(l%2==1)
    {
        int h;
        cout<<l<<' ';
        if(ans%n==0)
        {
            h=n;
        }
        else
        {
            h=ans%n;
        }
        cout<<h;
    }
    else
    {
        cout<<l<<' '<<(1+n)-ans%n;
    }
    return 0;
}
