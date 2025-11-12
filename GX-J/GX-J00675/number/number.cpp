#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin>>s;
    int b=-9;
    for(int i=0;i<=s.size();i++)
    {
        if(b<s[i])
        {
            b=s[i];
            cout<<s[i];
        }

    }
    return 0;
}
