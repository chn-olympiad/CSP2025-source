#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin >> a;
    int c = 0,b[a.size()];
    for (int x = 0;x < a.size();x++)
        if (a[x] >= '0' && a[x] <= '9')
        {
            b[c] = a[x] - 48;
            c++;
        }
    sort(b,b + c,cmp);
    for (int x = 0;x < c;x++)
        cout << b[x];
    return 0;
}
