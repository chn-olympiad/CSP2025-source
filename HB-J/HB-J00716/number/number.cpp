#include<bits/stdc++.h>
#define byGyf return
using namespace std;
string s;
int book[10]={0};
int flag=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]<='9'&&s[i]>='0')
        {
            if(s[i]!='0') flag=1;
            book[(int)(s[i]-'0')]++;
        }
    }
    if(flag==0)
    {
        cout<<0;
    }
    else
    {
        for(int i=9;i>=0;i--)
        {
            for(int j=1;j<=book[i];j++)
            {
                cout<<i;
            }
        }
    }
    byGyf 0;
}
