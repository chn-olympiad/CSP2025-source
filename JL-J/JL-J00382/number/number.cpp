#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int a[114514];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int sum=0;
    cin >>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]<='9' && s[i]>='0')
        {
            a[++sum]=(s[i]-'0');
        }
    }
    sort(a+1,a+1+sum,cmp);
    for(int i=1;i<=sum;i++)
    {
        cout <<a[i];
    }
    return 0;
}
