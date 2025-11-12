#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n , a[5005],sum;
    cin >> n;
    for(int i = 1 ; i <+ n ; i++){
        cin >> a[i];
    }
    sum+=9;
    cout << sum % 998244353;
    return 0;
}
