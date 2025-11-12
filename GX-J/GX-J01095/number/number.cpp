#include<bits/stdc++.h>
using namespace std;
string a;
char s[100001];
long long l=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            l++;
            s[l]=a[i];
        }
    }
    for(int i=1;i<=l;i++)
    {
        for(int j=1;j<=l-i;j++)
        {
            if(s[j]<s[j+1])swap(s[j],s[j+1]);
        }
    }
    for(int i=1;i<=l;i++)cout<<s[i];
    return 0;
}
