#include<bits/stdc++.h>
using namespace std;
string s;
int wyc;
int a[11];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s;
    // cout<<s;
    wyc=s.size();
    int i;
    i=0;
    while(i<wyc)
        {
            if(s[i]>='0'&&s[i]<='9')
                {
                    ++a[s[i]-'0'];
                }
            ++i;
        }
    i=9;
    while(i>=0)
        {
            while(a[i]!=0)
                {
                    cout<<i;
                    --a[i];
                }
            --i;
        }
    return 0;
}