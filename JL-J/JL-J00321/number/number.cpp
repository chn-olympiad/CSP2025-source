#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int x=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[++x]=s[i]-'0';
        }
    }
    sort(a+1,a+x+1);
    for(int i=x;i>=1;i--)
    {
        cout<<a[i];
    }
    return 0;
}
