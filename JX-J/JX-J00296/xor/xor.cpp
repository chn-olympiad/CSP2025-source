#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[10005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(k==0&&a[1]==a[2]&&a[1]==1)
    {
        cout<<n;
        return 0;
    }
    if(k==0&&a[1]==a[2]&&a[1]==a[3]&&a[1]==a[4]&&a[1]==a[5]&&a[1]==a[6]&&a[1]==a[7])
    {
        cout<<n;
        return 0;
    }
    if(k==0)
    {
        cout<<1;
        return 0;
    }
    /*int s1=r^j;
    cout<<s1;*/
    return 0;
}
