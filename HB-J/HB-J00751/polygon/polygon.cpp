#include<bits/stdc++.h>
using namespace std;
int n,ans = 0;
int m[3];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    cin>>m[0]>>m[1]>>m[2];
    if(m[0] + m[1] > m[2]) ans++;
    if(m[0] + m[2] > m[1]) ans++;
    if(m[1] + m[2] > m[0]) ans++;
    cout<<ans % 998244353;
    return 0;
}
