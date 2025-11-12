#include <bits/stdc++.h>

using namespace std;

string s;
int a[1000000];
int cnt, p;

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for(int i = 0; i <= 1000000; i++)
    {
        if(s[i] == '0')
        {
            a[cnt] = 0;
            cnt++;
        }
        else if(s[i] == '1')
        {
            a[cnt] = 1;
            cnt++;
        }
        else if(s[i] == '2')
        {
            a[cnt] = 2;
            cnt++;
        }
        else if(s[i] == '3')
        {
            a[cnt] = 3;
            cnt++;
        }
        else if(s[i] == '4')
        {
            a[cnt] = 4;
            cnt++;
        }
        else if(s[i] == '5')
        {
            a[cnt] = 5;
            cnt++;
        }
        else if(s[i] == '6')
        {
            a[cnt] = 6;
            cnt++;
        }
        else if(s[i] == '7')
        {
            a[cnt] = 7;
            cnt++;
        }
        else if(s[i] == '8')
        {
            a[cnt] = 8;
            cnt++;
        }
        else if(s[i] == '9')
        {
            a[cnt] = 9;
            cnt++;
        }
    }
    for(int i = 0; i <= cnt - 1; i++)
    {
        for(int j = i + 1; j <= cnt; j++)
        {
            if(a[j] > a[i])
                swap(a[i], a[j]);
        }
    }
    for(int i = 0; i <= cnt - 1; i++)
    {
        cout << a[i];
    }
    return 0;
}