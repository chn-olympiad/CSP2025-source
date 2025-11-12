#include <iostream>
using namespace std;
int n[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin >> a;
    for (int i = 0;i < a.length();i++)
    {
        if (a[i] == '0') n[0]++;
        else if (a[i] == '1') n[1]++;
        else if (a[i] == '2') n[2]++;
        else if (a[i] == '3') n[3]++;
        else if (a[i] == '4') n[4]++;
        else if (a[i] == '5') n[5]++;
        else if (a[i] == '6') n[6]++;
        else if (a[i] == '7') n[7]++;
        else if (a[i] == '8') n[8]++;
        else if (a[i] == '9') n[9]++;
    }
    for (int i = 9;i >= 0;i--)
    {
        for (int j = 1;j <= n[i];j++) cout << i;
    }
    return 0;
}
