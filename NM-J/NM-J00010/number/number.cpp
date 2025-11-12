#include <bits/stdc++.h>
using namespace std;
int x[1000005];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int num=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            num++;
            x[i]=s[i]-'0';
        }
    }
    sort(x,x+s.size(),cmp);
    for(int i=0;i<num;i++)
    {
        cout<<x[i];
    }
    return 0;
}
