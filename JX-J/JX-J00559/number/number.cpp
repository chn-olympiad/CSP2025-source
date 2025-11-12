#include <bits/stdc++.h>
using namespace std;
string s;
int sum=0;
string a[10000010];
bool cmp(string x,string y)
{
    return x>y;
}
int main()
{
    freopen("number.in",r,stdin);
    freopen("number.out",w,stdout);
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[i]=s[i];
            sum++;
        }
    }
    sort(a,a+n,cmp);
    for(int i=0;i<sum;i++)
    {
        cout<<a[i];
    }
    return 0;
}
