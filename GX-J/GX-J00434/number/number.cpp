#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[100005];
    int z=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]<='9'&&s[i]>='0')
        {
            z++;
            a[z]=s[i]-'0';
        }
    }
    sort(a+1,a+1+z,cmp);
    for(int i=1;i<=z;i++)cout<<a[i];
    return 0;
}
