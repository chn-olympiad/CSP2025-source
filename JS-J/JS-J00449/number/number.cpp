#include<bits/stdc++.h>
using namespace std;
string str;
int a[105];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>str;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            int pos=str[i]-'0';
            a[pos]++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=a[i];j++)
        {
            printf("%d",i);
        }
    }
    return 0;
}
