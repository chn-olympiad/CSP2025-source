#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number","r",stdin);
    freopen("number","w",stdout);
    int l[10]={0,0,0,0,0,0,0,0,0,0};
    string s;
    getline(cin,s);
    for(int i=0;i<s.size();i++)
    {
        if(s[i]<65) l[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=l[i];j++)
            cout<<i;
    }
    return 0;
}
