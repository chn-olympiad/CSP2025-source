#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
char c[101000];

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string str;
    cin >> str;
    int cnt=0;
    for (int i=0;i<str.size();i++)
    {
        if (str[i]>='0' && str[i]<='9')
        {
            c[++cnt]=str[i];
        }
    }
    sort(c+1,c+1+cnt);
    for (int i=cnt;i>=1;i--)
    {
        cout << c[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
