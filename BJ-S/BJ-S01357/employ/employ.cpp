#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;

long long jie(int x)
{
    int sum = 1;
    for (int i=1;i<=x;i++)
        sum *= i;
    return sum;
}

int main()
{
    //freopen("employ.in","r",stdin);
    //freopen("employ.out","w",stdout);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    string str;
    cin >> n >> m >> str;
    int a[m];
    for (int i=0;i<m;i++)
        cin >> a[i];
    cout << jie(n)/(jie(m)*jie(n-m))%mod;
    return 0;
}
