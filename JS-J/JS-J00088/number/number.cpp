#include<bits/stdc++.h>
using namespace std;
string s;
map<char,int> mrz;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();++i) mrz[s[i]]++;
    for(char i='9';i>='0';--i) 
        while(mrz[i]--) 
            cout<<(int)i-48;
    return 0;
}