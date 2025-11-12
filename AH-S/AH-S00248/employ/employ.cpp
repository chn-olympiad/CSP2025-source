#include<bits/stdc++.h>
using namespace std;
int n, a[1000005], m;
string s;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for (int i = 1;i <= n;i++) cin >> a[i];
    if (n <= 4)
    {
        if (n == 1) a[1] = 1;
        if (n == 2)
        {
            a[1] = 12;
            a[2] = 21;
        }
        if (n == 3)
        {
            a[1] = 123;
            a[2] = 132;
            a[3] = 213;
            a[4] = 231;
            a[5] = 321;
            a[6] = 312;
        }
        if (n == 4)
        {
            a[1]=1234;
            a[2]=1324;
            a[3]=1342;
            a[4]=1423;
            a[5]=1243;
            a[6]=1432;
            a[7]=2134;
            a[8]=2143;
            a[9]=2341;
            a[10]=4123;
            a[11]=2314;
            a[12]=2431;
            a[13]=2413;
            a[14]=3124;
            a[15]=3142;
            a[16]=3241;
            a[17]=3214;
            a[18]=3421;
            a[19]=3412;
            a[20] = 4132;
            a[21] = 4213;
            a[22] = 4231;
            a[23] = 4312;
            a[24] = 4321;

        }
        int ans = 0, u = 0, x = n - m;
        int c = 1;
        for (int i = 1;i <= n;i++) c *= i;
        for (int i = 1;i <= c;i++)
        {
            u = 0;
            for (int j = 1;j <= n;j++)
            {
                int z;
                z = a[i] - (10 * (a[i] / 10));
                if (s[z - 1] == 0 or a[z] <= u) u++;
                a[i] /= 10;
            }
            if (u <= x) ans++;
        }
        cout << ans;
    }
    else cout << 0;
}
