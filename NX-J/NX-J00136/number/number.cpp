#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.cpp.in","r",stdin);
    freopen("number.cpp.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<=9;i++)
    {
        if(s[0]==i)
        {
        cout<<s[0];
        }
    }
    for(int i=0;i<=s.size();i++)
    {
        for(int j=0;j<=9;j++)
        {
            if(s[i]==j)
            {
                cout<<j;
            }
        }
    }
    return 0;
}
