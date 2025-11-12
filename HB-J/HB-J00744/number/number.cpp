#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000003],l,b=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    l=s.size();
    for(int i=0;i<l;i++)
    {
        if (s[i]>='0' && s[i]<='9')
        {
            a[b]=(s[i]-'0');
            b++;
        }
    }
    sort(a,a+b);
    for (int i=b-1;i>=0;i--)
    {
        cout<<a[i];
    }
    return 0;
}
