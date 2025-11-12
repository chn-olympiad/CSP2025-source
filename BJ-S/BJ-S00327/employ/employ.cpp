#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,mul=1;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n;
    for(int i = 1; i<=n; i++)
    {
        mul*=i;
        mul%=MOD;
    }
    cout<<mul<<endl;
    return 0;
}
