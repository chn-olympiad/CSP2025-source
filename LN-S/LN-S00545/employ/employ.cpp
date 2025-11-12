#include<bits/stdc++.h>
using namespace std;
long long n,m,s,a[505];
string p;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    string p;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    s=1;
    for(long long i=2;i<=n;i++)
    {
        s=s*i%998244353;
    }
    cout<<s;
    return 0;
}
