#include<bits/stdc++.h>
using namespace std;
int a[1000005];
string s;
bool cmp(int q, int h)
{
    return q > h;
}
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    int k = 0;
    cin>>s;
    for(int i = 0;i < s.length();i++)
    {
        if(s[i] - '0' >= 0 && s[i] - '0' <= 9)
        {
            a[k] = s[i] - '0';
            k++;
        }
    }
    sort(a, a + k, cmp);
    for(int i = 0;i < k;i++)
    {
        cout<<a[i];
    }
    return 0;
}
