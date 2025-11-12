#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

char o[10000000];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int sb=0;
    for(int i=0;i<s.size();i++)
    {
        if(int(s[i])<65)
        {
            sb+=1;
            o[sb]=s[i];
        }
    }
    sort(o+1,o+1+sb);
    for(int p=sb;p>=1;p--)
    {

        cout<<o[p];
    }


}
