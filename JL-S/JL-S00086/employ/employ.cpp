#include<bits/stdc++.h>
using namespace std;
int c[100001];
long long x =1,y = 1;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string a;
    cin>>a;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    for(int i=1;i<=m;i++)
    {
        x*=i;
    }
    for(int i=1;i<=m;i++)
    {
        y*=(n-i+1);
    }
    cout<<y%998244353/x;
    return 0;
}
