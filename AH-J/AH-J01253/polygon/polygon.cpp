#include<bits/stdc++.h>
using namespace std;
long long n,i,j,k,a[1000005],s=0,maxn=-114514;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
        s+=a[i];
    }
    maxn*=2;
    if(s>maxn)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
//you have no egg
