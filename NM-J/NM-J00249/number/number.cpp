#include<bits/stdc++.h>
using namespace std;
string s;
int z[1000010];
int ma;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=1;i<=s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            z[i]+=s[i]-'0';
            cout<<s[i];
        }
    }
    for(int i=1;i<=s.size();i++)
    {
        if(z[i]>ma)
            ma+=z[i];
    }
    return 0;
}
