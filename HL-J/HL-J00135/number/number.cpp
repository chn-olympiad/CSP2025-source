#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n;
string s;
char a[100005];
long long cnt;

bool cmp(char x,char y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    long long len=s.size();
    for(int i=0;i<len;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
            a[++cnt]=s[i];
    }
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)
    {
        cout<<a[i];
    }
    return 0;
}
