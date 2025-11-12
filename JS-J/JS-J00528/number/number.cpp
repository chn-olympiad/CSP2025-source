#include <bits/stdc++.h>
using namespace std;
string s;
int a[100001];
int s1=0;
int cnt=0;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        s1=int(s[i]);
        if(s1>=48 && s1<=57)
        {
            cnt++;
            a[cnt]=s1-48;
        }
    }
    sort(a,a+s.size(),cmp);
    for(int i=0;i<cnt;i++)
    {

        cout<<a[i];
    }
    return 0;
}
