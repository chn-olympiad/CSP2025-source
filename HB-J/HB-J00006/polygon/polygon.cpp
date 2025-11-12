#include<bits/stdc++.h>
using namespace std;
unsigned long long cnt,len;
int a[5141],hc[5141];
int n,cn,smax=INT_MIN;
void dfs(int k,int num)
{
    if(k==cn)
    {
        if(len>(2*smax))
            cnt++;
    }
    for(int i=num;i<n;i++)
    {
        if(num>n-1)
            continue;
        hc[k]=a[i];
        len+=a[i];
        smax=a[i];
        dfs(k+1,i+1);
        len-=a[i];
    }
}
int main()
{
    ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
    freopen("polygon1.in","r",stdin);
    freopen("polygon.out","w",stdout)
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=3;i<=n;i++)
    {
        cn=i;
        len=0;
        smax=INT_MIN;
        dfs(0,0);
    }
    cout<<cnt%998%244%353;
    return 0;
}
