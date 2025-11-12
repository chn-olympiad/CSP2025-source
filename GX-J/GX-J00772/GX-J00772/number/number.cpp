#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int c[10]={0};
    string s;
    cin>>s;
    for(int i=0;i<s.size();++i)
        if(s[i]>='0'&&s[i]<='9')++c[s[i]-'0'];
    for(int i=9;i>=0;--i)for(;c[i]>0;--c[i])cout<<i;
    return 0;
}
