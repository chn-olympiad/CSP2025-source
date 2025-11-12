#include <iostream>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin)
    freopen("xor.out","w",stdout)
    int a, k, p[500000], q[500000], num;
    cin >> a >> k;
    cin >> p[1];
    for (int i = 2;i <= a;i++)
    {
        cin >> p[i];
        if (p[i] == k) num++;
        q[i] = p[i] & p[i - 1];
    }
    cout << num * 2;
}
