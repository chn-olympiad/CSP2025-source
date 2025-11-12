#include <bits/stdc++.h>
using namespace std;
int u[15];
string s;
int ch;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            u[(int)(s[i]-'0')]++;
            if((int)(s[i]-'0')!=0)
            {
                ch++;
            }
        }
    }
    if(ch==0)
    {
        printf("0");
        return 0;
    }
    else
    {
        for(int i=9;i>=0;i--)
        {
            for(int j=1;j<=u[i];j++)
            {
                printf("%d",i);
            }
        }
        return 0;
    }
    return 0;
}
