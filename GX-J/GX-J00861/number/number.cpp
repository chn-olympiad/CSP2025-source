#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int z=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            z++;
            a[z]=s[i]+'0'-96;
        }
    }
    sort(a+1,a+1+z);
    for(int i=z;i>=1;i--)
    {
        cout<<a[i];
    }
    return 0;
}
