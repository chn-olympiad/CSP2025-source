#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int n = 0;
    cin >> s;
    for(int i = 0;i < s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[++n] = int(s[i]-'0');
        }
    }
    sort(a+1,a+n+1);
    if(a[n]==0)
    {
        cout << 0;
        return 0;
    }
    for(int i = n;i >= 1;i--)
    {
        cout << a[i];
    }
    return 0;
}
