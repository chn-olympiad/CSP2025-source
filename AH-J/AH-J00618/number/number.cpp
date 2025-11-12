#include <bits/stdc++.h>

using namespace std;

string s;
int a[20];

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >>s;
    for(int k=0;k<s.size();k++)
    {
        if(s[k]<='9'&&s[k]>='0')
        {
            a[s[k]-'0']++;
        }
    }
    for(int k=9;k>=0;k--)
    for(int i=1;i<=a[k];i++)
        cout << k;
    return 0;
}
