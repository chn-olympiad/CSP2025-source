#include <bits/stdc++.h>
using namespace std;
int calc(vector<int> &v, int l, int r)
{
    int ans=v[l];
    for (int i = l+1; i <= r; i++)
    {
        ans^=v[i];
    }
    return ans;
}
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    if (n==2&&k==0)
    {
        if (v[0]==0 && v[1]==0) cout << 2;
        else if (v[0] == 0 || v[1]==0) cout << 1;
        else if (calc(v, 0, 1)==0) cout << 1;
        else cout << 0;
    }
    else if (n==1&&k==0) {
        if (v[0]==0) cout << 1;
    }
    return 0;
}
