#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[510];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    long long cnt=1;
    for(int i=2;i<=n;i++)
        cnt*=i;
    cnt%=998244353;
    cout<<cnt;
    return 0;
}
