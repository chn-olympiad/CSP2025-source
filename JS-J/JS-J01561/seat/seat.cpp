#include<bits/stdc++.h>
using namespace std;
int a[110];
int cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
       cin>>a[i];
    int cnt;
    cnt=a[1];
    sort(a+1,a+(n*m)+1,cmp);
    int ans;
    for(int i=1;i<=n*m;i++)
        if(a[i]==cnt)ans=i;
        if(ans%n==0)cout<<ans/n<<" ";
    else cout<<ans/n+1<<" ";
    if(ans%n==0)
    {
        if((ans/n)%2==1)cout<<n;
        else cout<<1;
    }
    else
    {
    int o=ans%n,k=(ans/n+1)%2;
    if(k==1)cout<<o;
    else cout<<n-o+1;
    }
    return 0;
}
