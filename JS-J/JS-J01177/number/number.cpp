#include<bits/stdc++.h>
using namespace std;

string s;
int tong[100];

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            tong[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=0;j<tong[i];j++)cout<<i;
    }

    return 0;
}
