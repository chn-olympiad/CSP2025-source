#include<bits/stdc++.h>
using namespace std;
int c[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i = 0;i < s.size();i++)
    {
        if(s[i]=='0') c[0]++;
        else if(s[i]=='1') c[1]++;
        else if(s[i]=='2') c[2]++;
        else if(s[i]=='3') c[3]++;
        else if(s[i]=='4') c[4]++;
        else if(s[i]=='5') c[5]++;
        else if(s[i]=='6') c[6]++;
        else if(s[i]=='7') c[7]++;
        else if(s[i]=='8') c[8]++;
        else if(s[i]=='9') c[9]++;
    }
    if(c[1]==0&&c[2]==0&&c[3]==0&&c[4]==0&&c[5]==0&&c[6]==0&&c[7]==0&&c[8]==0&&c[9]==0)
    {
        cout<<0;
        return 0;
    }
    for(int i = 9;i >= 0;i--)
    {
        for(int j = 1;j <= c[i];j++)
        {
            cout<<i;
        }
    }
    return 0;
}
