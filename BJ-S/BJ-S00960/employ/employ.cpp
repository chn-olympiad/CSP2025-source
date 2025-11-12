#include<bits/stdc++.h>
#define int long long
using namespace std;

int p(int x)
{
    if(x==0) return 1;
    else return (p(x-1)%998244353)*x;
}

int A(int n,int m)
{
    return p(n)/p(n-m);
}

signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cout<<A(n,m)%998244353<<endl;
    return 0;
}
