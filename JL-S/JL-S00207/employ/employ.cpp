#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=0; i<n; i++)
    {

        char s[10];
        cin>>s[i];
    }
    for (int i=0; i<n; i++)
    {

        int v;
        cin>>v;
    }
    long long ret=0;
    for (int i=m; i<=n; i++)
    {
        ret+=(i*(i+1))/2;

    }
    cout<<ret%998244353;
    return 0;
}


