#include<bits/stdc++.h>
using namespace std;
string s;
int f[15];
int main()
{
    freopen("number.in","r",stdin);
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(s[i]>='0'&&s[i]<='9')
            f[s[i]-'0']++;
    freopen("number.out","w",stdout);
    for(int i=9;i>=0;i--)
    {

        while(f[i]!=0)
        {
            cout<<i;
            f[i]--;
        }
    }
    return 0;
}
