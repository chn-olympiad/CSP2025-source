#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    string s1;
    s1="";
    for(long long i=0;i<s.size();i++)
    {
        if(s[i]<='9'&&s[i]>='0')s1+=s[i];
    }
    int a[s1.size()];
    for(long long i=0;i<s1.size();i++)
    {
        a[i]=s1[i]-'0';
    }
    sort(a,a+s1.size());
    for(long long i=s1.size()-1;i>=0;i--)
        cout << a[i] ;
    return 0;
}
