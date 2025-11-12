#include <bits/stdc++.h>
using namespace std;
int x[1005];
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    string s;
    cin >> s;
    int j=0;
    for (int i=0;i<s.size();i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            x[j]=s[i]-'0';
            j++;
        }
    }
    sort (x,x+j,cmp);
    for (int i=0;i<j;i++)
        cout << x[i];
}
