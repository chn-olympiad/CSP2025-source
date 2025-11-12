#include <bits/stdc++.h>
using namespace std;
string s;
int num[100000005],cou=1;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>47 && s[i]<58)
        {
            num[cou]=s[i]-48;
            cou++;
        }
    }
    sort(num+1,num+cou);
    for(int i=cou-1;i>=1;i--) cout<<num[i];
    return 0;
}
