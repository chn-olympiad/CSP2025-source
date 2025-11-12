#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    bool flag=false;
    if(x>y)
    {
        flag=true;
    }
    return flag;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    long long i=0;
    cin>>s;
    for(long long n=0;n<s.size();n++)
    {
        if(int(s[n])<=57&&int(s[n]>=48))
        {
            s[i]=s[n];
            i++;
        }
    }
    vector<long long> ar(i);
    for(int j=0;j<i;j++)
    {
        ar[j]=int(s[j])-48;
    }
    sort(ar.begin(),ar.end(),cmp);
    for(int j=0;j<i;j++)
    {
        cout<<int(ar[j]);
    }
    return 0;
}
