#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char s[100010];
    int a[100010],n = 0;
    cin>>s;
    for(int i = 0;i<strlen(s);i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[n] = s[i]-48;
            n++;
        }
    }
    for(int i = 0;i<n;i++)
    {
        cout<<a[i];
    }
    return 0;
}
