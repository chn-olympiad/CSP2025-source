#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int a[N],top=0;
string str;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,str);
    for(int i=0;i<str.size();i++)
    {
        if(str[i]>='0'&&str[i]<='9')
            a[++top]=str[i]-'0';
    }
    sort(a+1,a+top+1);
    for(int i=top;i;i--)
        printf("%d",a[i]);
    return 0;
}