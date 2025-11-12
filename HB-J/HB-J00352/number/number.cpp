#include<bits/stdc++.h>
using namespace std;
int a[9];
string s;
bool flag;
int main()
{
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        char ch=s[i];
        if(ch<='9'&&ch>='0')
        {
            a[ch-'0']++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        if(i==0&&!flag)
        {
            cout<<0;
            break;
        }
        while(a[i]>0)
        {
            flag=true;
            cout<<i;
            a[i]--;
        }
    }
    return 0;
}
