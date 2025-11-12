#include<bits/stdc++.h>
using namespace std;
const int P=998244353,N=5001;
int a[N],n,m,d,ld;
long long l;
bool cmp(int x,int y)
{
    return x>y;
}
void dg(int d,int sum)
{
    if(sum>m)
    {
        l++;
        l%=P;
    }
    for(int i=d;i<=n;i++)
    {
        dg(i+1,sum+a[i]);
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<n-1;i++)
    {
        l=0;
        m=a[i];
        dg(i+1,0);
        ans+=l%P;
        ans%=P;
    }
    cout<<ans;
    return 0;
}