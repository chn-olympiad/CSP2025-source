#include<bits/stdc++.h>
#define io freopen("number.in","r",stdin),freopen("number.out","w",stdout)
using namespace std;
string s;
vector<int> a;
int b[10];
int main()
{
    io;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i]))b[int(s[i]-48)]++;
    }
    for(int i=9;i>=0;i--)
    {
        while(b[i])
        {
            cout<<i;
            b[i]--;
        }
    }
    return 0;
}
