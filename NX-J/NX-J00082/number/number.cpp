#include <bits/stdc++.h>
using namespace std;
string b;
long long a[100005],cu;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> b;
    long long n = b.size();
    if (n == 1)
    {
        cout << b;
        return 0;
    }
    for (int i = 0;i < n;i++)
    {
        if (b[i]== '0'||b[i] == '1'||b[i] == '2'||b[i]=='3'||b[i] == '4'||b[i] == '5' || b[i] == '6' || b[i] == '7'||b[i] == '8' || b[i] == '9')
        {
            a[i+1] = (int)b[i]-48;
        }
        else
        {
            cu++;
        }
    }
    sort(a+1,a+n+1);
    for (int i = n;i >= cu+1;i--)
    {
        cout << a[i];
    }
    return 0;
}
