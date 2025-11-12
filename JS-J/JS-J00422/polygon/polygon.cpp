#include<bits/stdc++.h>
using namespace std;
const long long N=998244353;
int n;
long long ans;
int a[5010];
void f(int num,int maxn,int len)
{
    if(len==n)
    {
        if(maxn*2<num)
            ans=(ans+1)%n;
        return;
    }
    len++;
    f(num,maxn,len);
    num+=a[len];
    maxn=max(maxn,a[len]);
    f(num,maxn,len);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    f(0,0,0);
    cout<<ans;
    return 0;
}
