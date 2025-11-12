#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int r=a[1];
    sort(a+1,a+n*m+1);reverse(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==r) r=i;
    }
    int i=1,j=1;
    int c=1;
    for(int k=2;k<=r;k++)
    {
        if(i+c>n||i+c<1)j++,c=-c;
        else i+=c;
    }
    cout<<j<<' '<<i;
    return 0;
}