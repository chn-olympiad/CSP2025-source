# include <bits/stdc++.h>

using namespace std;

const int N=5e3+10;
const int mod=998244353;
int n;
int a[N];

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    cout << n*n%mod << endl;
    return 0;
}
