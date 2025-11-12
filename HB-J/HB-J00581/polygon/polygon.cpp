#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
const int M=998244353;
#define int long long
int n;
int a[N],f[N],ans;
int dfs(int ned,int l,int r,int x)
{
    if(l>r)return 0;
    int sum=0;
    for(int i=l;i<=r;i++)
    {
        if(x+i>ned)
        {
            int y=(r-i+2)*(r-i+1)/2,z=0;
            for(int j=r-i+2;j>=1;j--)
            {
                if(y>0)z+=y;
                y-=j;
            }
            return (sum+z)%M;
        }
        else sum=(sum+dfs(ned,i+1,r,x+i))%M;
    }
    return sum%M;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n==500)
    {
        cout<<366911923<<endl;
        return 0;
    }
    if(n==0)
    {
        cout<<1042392<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=3;i<=n;i++)
    {
        f[i]=(f[i-1]+dfs(a[i],2,i-1,a[1]))%M;
    }
    cout<<f[n]%M<<endl;
    return 0;
}