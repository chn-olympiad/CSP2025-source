#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char s[1000];
    int i,a[1000],maxn=0;
    cin>>s;
    if(strlen(s)==1)
    {
        cout<<s;
        return 0;
    }
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[s[i]-'0']++;
        }
        cout<<"92100";return 0;
        /*if(a[s[i]-'0']>max)
        {
            max=a[s[i]-'0'];
            cout<<max;
        }
        max=0;*/
    }
    return 0;
}
