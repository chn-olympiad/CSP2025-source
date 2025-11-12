#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[1000006]={};
    int now=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[now]=s[i]-48;
            now++;
        }
    }
    sort(a+1,a+now,cmp);
    for(int i=1;i<now;i++)
    {
        cout<<a[i];
    }

    return 0;
}
