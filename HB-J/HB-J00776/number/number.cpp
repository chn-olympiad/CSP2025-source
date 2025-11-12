#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int mn = 1e6 + 8;
int a[mn];
string s;
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int n = s.length();
    int cnt = 0;
    for(int i = 0;i < n;i++)
        if(s[i] >= '0' && s[i] <= '9')
            a[cnt++] = int(s[i] - '0');

    sort(a ,a + cnt ,cmp);

    for(int i = 0;i < cnt;i++)
    {
        cout << a[i];
    }
    return 0;
}
