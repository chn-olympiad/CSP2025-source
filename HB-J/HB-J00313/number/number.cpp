#include<bits/stdc++.h>
#define ll long long
const int N=1e6+10;
long long s[N],z[N],a[N];
void solve()
{
    std::cin>>s[N];
    for(int j=1;j<=9;j++)
    {
        for(int i=1;i<=N;i++)
        {
            if(s[i]==j)
            z[j]++;
        }
    }
    for(int i=9;i>=1;i--)
    {
        if(z[i]>0)
        {
            for(int j=1;j<=z[i];j++)
            {
                 std::cout<<i;
            }
        }
    }
}
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    solve();
    return 0;
}
