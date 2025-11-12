#include<bits/stdc++.h>
using namespace std;
char a[1000];
char s[1000];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin.getline(s,1000);
    int len=strlen(s);
    int biao=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
        {
            a[biao]=s[i];
            biao++;
        }
    }
    for(int i=0;i<biao;i++)
    {
        for(int j=i+1;j<biao;j++)
        {
            if(a[j]>a[i])
            {
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=0;i<biao;i++)
    {
        cout<<a[i];
    }
    return 0;
}
