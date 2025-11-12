#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
     freopen("number.out","w",stdout);

    int text=0;
    char s[100000];
    char a[100000];
    cin>>s;
    int str=strlen(s);
    for(int i=0;i<str;i++)
    {
        if('0'<=s[i]&&'9'>=s[i])
        {
            a[text]=s[i];
            text++;
        }
    }
    sort(a,a+text);
    for(int i=text-1;i>=0;i--)
    {
        cout<<a[i];
    }
}
