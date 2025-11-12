#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[1000005];
string s;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    int pos=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]>='0'&&s[i]<='9')
        {
            a[i]=s[i]-48;
            pos++;
        }
    }
    sort(a,a+n,cmp);
    for (int i=0;i<pos;i++)
    {
        cout<<a[i];
    }
    return 0;
}
