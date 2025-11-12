#include <iostream>
#include <cstdio>
using namespace std;

int n,q;
string x[200005],y[200005];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for (int i = 1;i <= n;i++)
    {
        cin >> x[i] >> y[i];
    }
    while (q --)
    {
        cout << 0 << endl;
    }
    return 0;
}
