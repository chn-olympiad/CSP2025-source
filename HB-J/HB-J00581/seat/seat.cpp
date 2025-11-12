#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m;
int a[N],s,num=1;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    s=a[1];
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
        if(a[i]>s)num++;
    }
    int l=(num-1)/n+1;
    int r=num-(l-1)*n;
    if(l%2==0)r=n-r+1;
    cout<<l<<' '<<r;
    return 0;
}
/*
2 3
10 100 30 15 20 35
*/