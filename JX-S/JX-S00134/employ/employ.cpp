#include<bits/stdc++.h>
using namespace std;
long long p(int x)
{
    long long sum = 1;
    for(int i = 1;i<=x;i++)
    {
        sum = sum*x;
        sum%=998244353;
    }
    return sum;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin >> n >> m;
    cout << p(n);
    return 0;
}
