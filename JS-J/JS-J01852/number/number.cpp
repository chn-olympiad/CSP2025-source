#include <bits/stdc++.h>
using namespace std;

string s;
int a[1010000];
int Index = 0;
bool cmp(int a,int b)
{
    return(a > b);
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 0;i < s.length();i++)
    {
        if(s[i] <= '9' && s[i] >= '0')
        {
            a[Index++] = s[i] - '0';
        }
    }
    sort(a,a + Index,cmp);
    if(a[0] == 0 && a[1] == 0)
    {
        cout << 0;
        return 0;
    }
    for(int i = 0;i < Index;i++)
    {
        cout << a[i];
    }
    return 0;
}
