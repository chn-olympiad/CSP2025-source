#include<bits/stdc++.h>
using namespace std;
long long n,s,a[5005],cnt,ans=-1;
int b[5005];
void dg(int k,int x,int y){
    if (x>n) return;
    if (k==1) s+=a[x];
    if (y>=3&&s>2*a[x]) cnt++;
    dg(0,x+1,y);
    ans=max(ans,cnt);
    cnt=0;
    dg(1,x+1,y+1);
    ans=max(ans,cnt);
    cnt=0;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    dg(0,1,0);
    s=0;
    dg(1,1,1);
    cout<<ans%998244353;
    return 0;
}
