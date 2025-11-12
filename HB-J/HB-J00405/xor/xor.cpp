#include <bits/stdc++.h>
using namespace std;
int a[1000005] = {};
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    string s;
    cin >> s;
    int c = 0;
//    cout << s.size()<<"~";
    for (int i = 0;i<s.size();i++)
    {
        if (s[i]>='0'&&s[i]<='9')
        {
            c++;
            a[c] = s[i]-'0';
//            cout << a[c]<<"@";
        }
    }
    sort(a+1,a+c+1,cmp);
    for (int i = 1;i<=c;i++)
    {

        cout << a[i];

    }
//    cout << "~"<<c;
    return 0;
}
