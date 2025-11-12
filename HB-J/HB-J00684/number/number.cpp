#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+100;
int a[N];
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int sum = 0;
    cin >> s;
    int n = s.length();
    for(int i = 0; i<= n-1; i++)
    {
        char m = s[i];
        if(s[i] == '0')
        {
            a[i] += 0;
            sum++;
        }
        else if(s[i] == '1')
        {
            a[i] += 1;
            sum++;
        }
        else if(s[i] == '2')
        {
            a[i] += 2;
            sum++;
        }
        else if(s[i] == '3')
        {
            a[i] += 3;
            sum++;
        }
        else if(s[i] == '4')
        {
            a[i] += 4;
            sum++;
        }
        else if(s[i] == '5')
        {
            a[i] += 5;
            sum++;
        }
        else if(s[i] == '6')
        {
            a[i] += 6;
            sum++;
        }
        else if(s[i] == '7')
        {
            a[i] += 7;
            sum++;
        }
        else if(s[i] == '8')
        {
            a[i] += 8;
            sum++;
        }
        else if(s[i] == '9')
        {
            a[i] += 9;
            sum++;
        }
    }
    sort(a,a+n);
    for(int i = n-1; i >= n-sum; i--)
    {
        cout << a[i];
    }
    return 0;
}
