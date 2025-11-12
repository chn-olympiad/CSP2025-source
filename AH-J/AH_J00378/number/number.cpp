#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[1000005],num=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(s[i]>='0'&&s[i]<='9')
            a[num++]=s[i]-'0';
    sort(a,a+num,cmp);
    for(int i=0;i<num;i++)
        cout<<a[i];
    return 0;
}
