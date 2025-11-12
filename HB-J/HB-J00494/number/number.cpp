#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<char,int,greater<char>>mp;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]<='9'&&s[i]>='0')mp[s[i]]++;
    }
    for(auto i:mp)
    {
        for(int j=0;j<i.second;j++)
            cout<<i.first;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
