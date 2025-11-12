#include<bits/stdc++.h>
using namespace std;
int k[100005],m;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;

    for(int i=0;i<s.length();i++)
    {
        if('0'<=s[i]&&s[i]<='9')
        {
            m++;

            k[m]=s[i]-'0';
        }
    }
    sort(k+1,k+m+1);
    reverse(k+1,k+m+1);
    for(int i=1;i<=m;i++)
    {
        cout<<k[i];
    }
    return 0;
}
