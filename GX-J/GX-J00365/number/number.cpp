#include<bits/stdc++.h>
using namespace std;

string s;
int a[100005],b[100005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='a'&&s[i]<='z')
            a[i]=-1;
        else
            a[i]=int(s[i]);
    }
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(a[i]!=-1)
        {
            b[i]=a[i];
            a[i]=-1;
        }
        else
            b[i]=-1;
    }
    sort(b,b+n);
    for(int i=n-1;i>-1;i--)
    {
        if(b[i]==-1)
            continue;
        else
            cout<<b[i]-48;
    }
}
