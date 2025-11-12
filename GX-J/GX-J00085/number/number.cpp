#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int b=1;
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.length();i++)
    {
        if('0'<=s[i] && s[i]<='9')
        {
            a[b]=s[i]-'0';
            b++;
        }
    }
    sort(a+1,a+b+1);
    for(int i=b;i>1;i--)
    {
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}
