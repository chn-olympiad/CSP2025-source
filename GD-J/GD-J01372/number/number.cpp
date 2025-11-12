#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int len=s.length();
    vector<int> a(10);
    for(int i=0;i<len;i++)
    {
        if(isdigit(s[i]))
        {
            a[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        while(a[i])
        {
            cout<<i;
            a[i]--;
        }
    }
    return 0;
}
