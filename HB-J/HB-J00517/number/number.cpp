#include <bits/stdc++.h>
using namespace std;
int a[10000001];
string s;
bool cmp(int a , int b)
{
    return a > b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out" , "w" , stdout);
    getline(cin , s);
    int sum = 1;
    for (int i = 0;i < (int)s.length();i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            int num = s[i] - '0';
            a[sum] = num;
            sum++;
        }
    }
    sort(a + 1, a + sum+ 1, cmp);
    for (int i = 1;i <sum;i++)
        cout << a[i];
    return 0;
}

