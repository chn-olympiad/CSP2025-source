#include<bits/stdc++.h>
#define ll long long
const int N=2e10+10;
int n,k,a[20000000],ans;
void solve()
{
    std::cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        std::cin>>a[i];
    }
    ans=a[1];
    std::cout<<ans;
}
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    solve();
    return 0;
}
