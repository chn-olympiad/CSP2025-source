#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    if( s.size() == 1 && s[0]-'0'>=0 && s[0] -'0' <= 9 ) cout<<s[0]-'0';
    if( s.size() == 2 )
    {
        if(s[0]-'0'>=0 && s[0] -'0' <= 9)
        {
            if( s[ 0 ]-'0'< 0 || s[0] -'0' > 9 ) cout<<s[0];

             else cout<<max(s[0]-'0',s[1]-'0')<<min(s[0]-'0',s[1]-'0');
        }
        else if(s[0]-'0'< 0 || s[0] -'0' > 9)
        {
            if( s[ 1 ]-'0'>= 0 && s[1] -'0' <= 9 ) cout<<s[1];
        }
    }
    return 0;
}
