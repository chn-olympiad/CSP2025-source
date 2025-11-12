
#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{

    //freopen("polygon.in", "r", stdin);
    //freopen("polygon.out", "w", stdout);
    const char endl = '\n';
    ios::sync_with_stdio(false);
    cin.tie();

    int n;
    cin >> n;

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }


    int i1 = 0, j1 = 1;
    int ij1 = max(a[i1], a[j1]);
    if(a[i1] + a[j1] > (2 * ij1)) ans++;


    int i2 = 0, j2 = 2;
    int ij2 = max(a[i2], a[j2]);
    if(a[i2] + a[j2] > (ij2 * 2)) ans++;

    int i3 = 1, j3 = 2;
    int ij3 = max(a[i3], a[j3]);
    if(a[i3] + a[j3] > (ij3 * 2)) ans++;

    int i4 = 0, j4 = 2, z = 1;
    int ij4 = max(max(a[i4], a[j4]), a[z]);
    if(a[i4] + a[j4] + a[z] > (ij4 * 2)) ans++;

    cout << ans;
    return 0;
}

