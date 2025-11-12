#include<bits/stdc++.h>
using namespace std;
string s;
int n=0,a[1000010];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(s[i]>='0'&&s[i]<='9')
            a[n++]=s[i]-'0';
    sort(a,a+n);
    for(int i=n-1;i>=0;i--)
        printf("%d",a[i]);
    return 0;
}
