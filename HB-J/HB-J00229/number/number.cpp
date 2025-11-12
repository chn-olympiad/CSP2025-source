#include<bits/stdc++.h>
using namespace std;
const int mx=1100000;
string s;
int a[mx],b[mx],i,j=0,l,x;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    l=s.size();
    for(i=0;i<=l-1;i++)
    if(s[i]>='0' && s[i]<='9')a[j++]=s[i]-48;
    for(i=0;i<=j-1;i++)b[a[i]]++;
    for(i=9;i>=0;i--)
    while(b[i]>0)
    {
        b[i]--;
        cout<<i;
    }
    return 0;
}
