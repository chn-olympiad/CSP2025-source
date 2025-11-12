#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    for(int i=s.size()-1;i>=0;i--)
    {
        if(isdigit(s[i]))
        {
            cout<<s[i];
        }
    }
    return 0;
}
