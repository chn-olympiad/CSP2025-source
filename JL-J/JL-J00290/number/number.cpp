#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[50000];
    int c=1;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[c]=s[i]-'0';
            c++;
        }
    }
    c--;
    sort(a+1,a+1+c);
    for(int i=c;i>=1;i--)
    {
        cout<<a[i];
    }
    return 0;
}
