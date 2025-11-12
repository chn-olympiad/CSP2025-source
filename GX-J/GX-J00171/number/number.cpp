#include<bits/stdc++.h>
using namespace std;
char a[1000010];
int shu[1000010];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int ans,j=0,i1=0;
    string s;
    cin>>s;
    if(s[1]==false)
    {
        cout<<s;
        return 0;
    }
    if(s[2]==false)
    {
        if(s[0]<s[1])
        {
            cout<<s[1]*10+s[0];
            return 0;
        }
        return 0;
    }
    return 0;
}
