#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long tj=0,a[1000000];
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            tj++;
            a[tj]+=s[i]-'0';
        }
    }
    sort(a+1,a+tj+1);
    for(int i=tj;i>=1;i--)
    {
        cout<<a[i];
    }
    return 0;
}
