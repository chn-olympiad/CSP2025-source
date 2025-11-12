#include <bits/stdc++.h>
using namespace std;
queue<int>q;
int a[1000005],num;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            q.push(s[i]);
        }
    }
    for(int i=1;i<=s.length();i++)
    {
        a[i]=q.front();
        q.pop();
        num++;
        if(q.empty())
        {
            break;
        }
    }
    sort(a+1,a+num+1);
    for(int i=num;i>=1;i--)
    {
        cout << a[i];
    }
    return 0;
}
