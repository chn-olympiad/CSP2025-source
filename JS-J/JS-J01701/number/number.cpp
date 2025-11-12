#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,b;
    cin>>s;
    for(int i=0;i<=s.length();i++)
    {
        b=s[i];

        if(b=="0"||b=="1"||b=="2"||b=="3"||b=="4"||b=="5"||b=="6"||b=="7"||b=="8"||b=="9")
        {
            cout<<b;
        }
    }
    cout<<5;
    return 0;
}
