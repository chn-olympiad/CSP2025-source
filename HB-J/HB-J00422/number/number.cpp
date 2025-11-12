#include <bits/stdc++.h>
using namespace std;
string s;
long long sum=0;
char a[999999];
bool cmp(char x,char y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[sum]=s[i];
            sum++;
        }
    }
    sort(a,a+sum,cmp);
    for(int i=0;i<sum;i++)
    {
        cout<<a[i];
    }
    return 0;
}
