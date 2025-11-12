#include<bits/stdc++.h>
using namespace std;
int N=1e6+10;
int r[20];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    bool n=0;
    for(int i=0;i<=s.size()-1;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            r[s[i]-'0']++;
        }
    }
    string ans;
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=r[i];j++)
        {
            if(i==0&&j==r[i])
            {
                cout<<"0";
                break;
            }
            if(n==0&&i==0)continue;
            n=1;
            cout<<i;
        }

    }

    return 0;
}
