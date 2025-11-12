#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int num[1000010];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=strlen(s);
    int tot=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            num[tot++]=(s[i]-'0');
        }
    }
    sort(num,num+tot);
    for(int i=tot-1;i>=0;i--)
    {
        cout<<num[i];
    }
    return 0;
}
