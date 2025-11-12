#include <bits/stdc++.h>
using namespace std;
int sum[15];
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int a=s.size();
    for (int i=0;i<a;i++)
    {
        if (s[i]>='0'&&s[i]<='9')sum[s[i]-'0']++;
    }
    for (int i=9;i>=0;i--)
    {
        for (int j=sum[i];j>0;j--)cout<<i;
    }
    return 0;
}
