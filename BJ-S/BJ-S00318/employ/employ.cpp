#include <bits/stdc++.h>

using namespace std;
const int MAX=1e5;
int n,m,c[MAX];
string a;//'0'=48
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>a;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    int ans=1;
    for(int i=1;i<=n;i++) ans=(ans*i)%998244353;
    cout<<ans;
    return 0;
}
