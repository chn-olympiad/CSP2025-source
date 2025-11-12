#include<bits/stdc++.h>
using namespace std;
map<int,long long> t;
string s;
long long i,j;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        if(s[i]<='9'&&s[i]>='0')
        {
            t[s[i]-'0']++;
        }
    }
    for(i=9;i>=0;i--)
    {
        while(t[i]>0)
        {
            cout<<i;
            t[i]--;
        }
    }
    return 0;
}
