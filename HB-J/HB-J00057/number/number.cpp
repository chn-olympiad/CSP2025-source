#include<bits/stdc++.h>
using namespace std;
#define Int long long
#define el '\n'
string s;
int main()
{
    //number
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s,'\n');
    for(int i=0;i<s.size();++i) if(s[i]<'0'||s[i]>'9') s.erase(i,1),i--;
    stable_sort(s.begin(),s.end(),greater<char>());
    cout<<s<<el;
    return 0;
}
