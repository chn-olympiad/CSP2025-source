#include<bits/stdc++.h>
using namespace std;
string s;
int tong[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for (int i=0;i<s.size();i++)
    {
        if(s[i]<='9' || s[i]>='0')
        {
            tong[s[i]-'0']++;
        }
    }
    int flag=0;
    if(tong[9]==0 && tong[8]==0 && tong[7]==0 && tong[6]==0 && tong[5]==0 && tong[4]==0 && tong[3]==0 && tong[2]==0 && tong[1]==0)
    {
        cout<<0;
    }
    else
    {
        for (int i=9;i>=0;i--)
        {
            if(tong[i]==0)
            {
                continue;
            }
            for (int j=0;j<tong[i];j++)
            {
                cout<<i;
            }
        }
    }
    return 0;
}
