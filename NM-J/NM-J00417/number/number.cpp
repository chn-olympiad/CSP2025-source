#include<bits/stdc++.h>
using namespace std;
string s;
int a[1001000],lena=1;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[lena]=(s[i]-'0');
            lena++;
        }
    }
    sort(a+1,a+lena);
    for(int i=lena-1;i>=1;i--)
    {
        printf("%d",a[i]);
    }
    return 0;
}
