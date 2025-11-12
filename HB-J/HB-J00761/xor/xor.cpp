#include <bits/stdc++.h>
using namespace std;


int a[99999];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    for (int i = 0;i<n;i++)
    {
        cin >> a[i];
    }
    //pf1
    if (n<=2 || k == 0) cout << 1 << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
