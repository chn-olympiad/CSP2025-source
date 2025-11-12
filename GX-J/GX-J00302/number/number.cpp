#include<bits/stdc++.h>
using namespace std;
long long num[1000002],len;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >>s;
    for(long long i=0;i<s.size();i++)
    {
            len++;
            num[len]=int(s[i]-'0');
    }
    sort(num+1,num+len+1);
    for(long long i=len;i>=1;i--)
    {
        if(num[i]<=9)
        cout<<num[i];
    }
    return 0;
}
