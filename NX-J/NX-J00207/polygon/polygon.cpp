#include <bits/stdc++.h>
using namespace std;
int a[50005],s[500005],cnt;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);`
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        s[i]=s[i-1]+a[i];
        for(int j=i;j<=n;j++)
        {
           if(a[i]+s[j]<s[i]&&a[i]!=s[i]!=s[j])cnt++;
        }
    }
    cout<<cnt-1;


    return 0;
}
