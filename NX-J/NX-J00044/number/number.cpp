#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    freopen("numberin","r",stdin);
    freopen("numberout","w",stdout);
    string s;
    cin >> s;
    long long a[100000005]={0},b=1;
    for(int i=0;i<=s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='0')
        {
            a[b]=s[i];
            b++;
        }
    }
    sort(a+1,a+1+b);
    for(int i=b;i>1;i--)
    {
        cout << a[i];
    }
    return 0;
}