#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int a[1000010],top;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[top++]=-(s[i]-'0');
        }
    }
    sort(a,a+top);
    for(int i=0;i<top;i++)
    {
        printf("%d",-a[i]);
    }
    return 0;
}
