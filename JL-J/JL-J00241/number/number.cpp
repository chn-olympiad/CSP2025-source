#include <bits/stdc++.h>
using namespace std;
int a[15];
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[s[i]-'0']++;
            //cout<<s[i]<<" "<<s[i]-'0'<<endl;
        }
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=a[i];j++)
        {
            cout<<i;
            //cout<<i<<" "<<ans<<endl;
        }
    }
    return 0;
}
