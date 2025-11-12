#include<bits/stdc++.h>
using namespace std;
int h[15];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i])) h[int(s[i]-48)]++;
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=h[i];j++) cout<<i;
    }
    cout<<'\n';
    return 0;
}
