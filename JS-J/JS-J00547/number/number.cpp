#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int a[1000005]={},k=1;
    for (int i=0;i<s.length();i++)
    {
        if (s[i]>='0'&&s[i]<='9')
        {
            a[k++] = s[i]-'0';
        }
    }
    sort(a+1,a+k,cmp);
    for (int i=1;i<k;i++)
    {
        cout << a[i];
    }
    return 0;
}
