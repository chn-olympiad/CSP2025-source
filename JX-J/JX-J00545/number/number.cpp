#include<bits/stdc++.h>
using namespace std;
string a;
void sw(int x)
{
    for(int i = 1;i<=x;i++)
    {
        for(int j = 2;j<=x;j++)
        {
            if(a[j]>a[j-1])
            {
                swap(a[j],a[j-1]);
            }
        }
    }
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int n=0;
    cin>>s;
    for(int i = 1;i<=s.length();i++)
    {
        if(s[i-1]>='0'&&s[i-1]<='9')
        {
            a[i]=s[i-1];
            n++;
        }
    }
    sw(n);
    for(int i = 1;i<=n;i++)
    {
        cout<<a[i];
    }
    return 0;
}
