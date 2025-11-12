#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m,cnt=0,flag=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==m)cnt++;
        if(a[i]!=1)flag=0;
    }
    if(flag)
    {
        if(n%2==0)
            cout<<0;
        else
            cout<<1;
    }
    else
    {
        cout<<cnt;
    }
    return 0;
}
