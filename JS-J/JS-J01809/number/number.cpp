#include<bits/stdc++.h>
#define ln "\n"
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string x;
    cin>>x;
    map<char,int> mapp;
    for(int i=0;i<x.size();i++)
    {
        mapp[x[i]]++;
    }
    string ans;
    for(char i='9';i>='0';i--)
    {
        for(int j=1;j<=mapp[i];j++)
        {
            ans+=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
