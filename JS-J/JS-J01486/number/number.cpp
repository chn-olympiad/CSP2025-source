#include<bits/stdc++.h>
using namespace std;
string s;
long long num=0,nu[1000005],ans;
bool cmp(long long a,long long b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(long long i=0;i<s.size();i++)
    {
        if(s[i]-'0'<=9 and s[i]-'0'>=0)
        {
            nu[num]=s[i]-'0';
            num++;
        }
    }
    sort(nu,nu+num,cmp);
    for(long long i=0;i<num;i++)
    {
        cout<<nu[i];
    }
    return 0;
}
