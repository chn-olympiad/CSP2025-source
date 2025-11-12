#include<bits/stdc++.h>
using namespace std;
string s1;
int a[101000];
int n;
bool cmp(int h1,int h2)
{
    return h1>h2;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s1;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]>='0'&&s1[i]<='9')
            a[++n]=s1[i]-'0';
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        cout<<a[i];
    }
    return 0;
}
