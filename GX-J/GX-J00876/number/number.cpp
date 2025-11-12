#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long sz[1000000]={78};
    if(s.size()==1)
    {cout<<s;
    return 0;}
    for(int i=1;i<=s.size();i++)
        sz[i]=78;
    for(int i=0;i<s.size();i++)
    {
         if(s[i]>='0'&&s[i]<='9'){sz[i]=s[i]-48;}
    }
    sort(sz,sz+1+s.size());
    for(int i=s.size();i>=0;i--)
    {
         if(sz[i]!=78)cout<<sz[i];
    }
    return 0;
}
