#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
string s,num;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>=48&&s[i]<=57)
        {
             num+=s[i];
        }
    }
    int a=num.size();
    sort(num.begin(),num.end());
    for(int i=num.size();i>=0;i--)
    {
        cout<<num[i];
    }
    return 0;
}

