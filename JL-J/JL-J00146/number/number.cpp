#include<bits/stdc++.h>
using namespace std;
string a;
int l=0,b[10005];
int cmp(int x,int y)
{
    return y<x;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<=a.size();i++)
    if(a[i]>='0'&&a[i]<='9')
    {
        l++;
        b[l]=a[i]-48;
    }
    sort(b+1,b+l+1,cmp);
    for(int i=1;i<=l;i++)cout<<b[i];
    return 0;
}
