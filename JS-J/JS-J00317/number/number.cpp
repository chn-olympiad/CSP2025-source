#include<bits/stdc++.h>
using namespace std;
string s;int a[1000005],sz;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'
           ||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'
           ||s[i]=='8'||s[i]=='9')
        {
            sz++;
            a[sz]=s[i]-'0';
        }
    }
    stable_sort(a+1,a+1+sz,greater<int>());
    for(int i=1;i<=sz;i++)
    {
        cout<<a[i];
    }
    return 0;
}
