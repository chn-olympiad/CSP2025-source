#include <bits/stdc++.h>
using namespace std;
int n,m;
int d[505];
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++)
    {
       cin>>d[i];
    }
    long long sum=1;
    for(int i=2;i<=n;i++)
    {
        sum=(sum*i)%998244353;
    }
    cout<<sum;
    return 0;
}