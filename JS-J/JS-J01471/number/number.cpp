#include <bits/stdc++.h>
using namespace std;
string str;
int k;
int a[1000100];
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> str;
    for(int i = 0;i < str.size();i++)
    {
        if(str[i] - '0' >= 0 && str[i] - '0' <= 9) 
        {
            a[k] = str[i] - '0';
            k++;
        }
    }
    sort(a, a+k);
    for(int i = k-1;i >= 0;i--) cout << a[i];
    cout << endl;
    return 0;
}