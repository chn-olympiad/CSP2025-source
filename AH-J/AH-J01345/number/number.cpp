#include<bits/stdc++.h>
using namespace std;
string s,s1;
bool cmp(int x,int y)
{
    return x>y;
}
int a[100000000];
int main(void)
{
    long long c=0;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[c]=s[i]-'0';
            c++;
        }
    }
    sort(a,a+c,cmp);
    for(int i=0;i<c;i++)cout<<a[i];
    return 0;
}
