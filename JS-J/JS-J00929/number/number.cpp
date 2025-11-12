#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int n,i;
    cin>>s;
    n=s.size();
    int a[10]={0},w=0;
    for(i=0;i<n;i++)
    if(s[i]>=48 && s[i]<=57)a[s[i]-48]=a[s[i]-48]+1;
    for(i=9;i>=0;i--)for(int j=1;j<=a[i];j++)cout<<i;
    return 0;
}
