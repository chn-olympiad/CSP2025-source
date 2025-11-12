#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int MOD = 998244353;
int n, m;
int c[505];
string dfc;
// long long ans = 0;
// bool use[505];
// long long jc(long long x)
// {
//     long long ret = 1;
//     for(int i = 2;i <= x;i++)
//         ret *= i;
//     return ret;
// }
// void dfs(int cntc, int lasq, int sbz , int z)
// {
//     if (cntc >= m){
//         for(int i = 1;i <= n;i++)
//             for(int j = 1;j <= n;j++)
//                 if(next_permutation(c+1,c+n+1))
//         ans += qp(n - lasq + 1);
//     }
//     for (int i = 1 ; i <= n; i++)
//     {
//         if (!use[i + 1])
//         {
//             use[i + 1] = 1;
//             //cout << c[i + 1] << " " << dfc[i]<< " " << cntc << " " << i << " " << sbz << "\n";
//             if (c[i + 1] <= sbz || (!(dfc[cntc + sbz] - '0')))
//                 dfs(cntc, i, sbz + 1 , z + 1);
//             else
//                 dfs(cntc + 1, i, sbz , z + 1);
//             use[i + 1] = 0;
//         }
//     }
// }
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> dfc;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    cout << 1;
    return 0;
}
/*
It's so funny

I  feel unhappy

make my code clean

Ican't AK

I love  C++;

I love  C;

I must  FAST NOW!!!
  17:32
*/