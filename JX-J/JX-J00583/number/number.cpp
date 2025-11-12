#include<bits/stdc++.h>
using namespace std;
char a[100010];
bool cmp(char x,char y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int t=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>=48&&s[i]<=57)
        {
            a[t]=s[i];
            t++;
        }
    }
    sort(a,a+t,cmp);
    for(int i=0;i<t;i++)
    {
        cout<<a[i];
    }
    return 0;
}

