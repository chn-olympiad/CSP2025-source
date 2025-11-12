#include <bits/stdc++.h>
#include <cstdio>
#define int long long
using namespace std;

const int mod=998244353;
int read()
{
    int x=0,f=1;
    char c;
    c=getchar();
    while((c<'0'||c>'9')&&c!='-')   c=getchar();
    if(c=='-')
    {
        f=-1;
        c=getchar();
    }
    while('0'<=c&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}

int arr[100005],a[100005],maxn;
int low_bit(int x){  return (x&(-x));}
void add(int pos,int x)
{
    while(pos<=maxn)
    {
        arr[pos]+=x;
        arr[pos]%=mod;
        pos+=low_bit(pos);

    }
    return;
}
int f(int pos)
{
    int ans=0;
    while(pos)
    {
        ans+=arr[pos];
        pos-=low_bit(pos);
        ans%=mod;
    }
    return ans;
}


signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    int n,ans=0;
    n=read();
    for(int i=1;i<=n;i++)   a[i]=read();
    sort(a+1,a+n+1);
    maxn=a[n];

    add(a[1]+a[2],1);

    int x=4;
    for(int i=3;i<=n;i++)
    {
        int c=i-1;
        //cout<<x-f(a[i])-1-c<<" "<<f(a[i])<<endl;
        ans+=x-f(a[i])-1-c;
        ans=((ans%mod)+mod)%mod;

        for(int j=maxn;j>a[i];j--)  add(j,f(j-a[i])-f(j-a[i]-1));
        for(int j=1;j<i;j++)    add(a[i]+a[j],1);

        x*=2;
        x%=mod;

    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
