#include<bits/stdc++.h>
using namespace std;

string is;
int a[10];

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> is;
    for (int i = 0; i <= is.size(); i++)
        if (isdigit(is[i]))
            a[is[i]-'0']++;
    for (int i = 9; i >= 0; i--)
    {
        while (a[i] > 0)
        {
            cout << i;
            a[i]--;
        }
    }
    return 0;
}
