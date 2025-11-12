#include<bits/stdc++.h>
using namespace std;

string a;
int s[100010];int n=0;
bool cmp(int z,int x)
{
    return z>x;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]-'0'>=0&&a[i]-'0'<=9)s[n++]=a[i]-'0';
    }
    sort(s,s+n,cmp);
    for(int i=0;i<n;i++)cout<<s[i];
    cout<<endl;return 0;
}
