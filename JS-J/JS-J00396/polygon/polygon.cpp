#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int MAXN=5000+10;
int a[MAXN];
long long s(int m,int n,int cn,long long ans,int cnt)
{
    if(m==0)
    {
        if(ans%mod>(2*cnt)%mod) return ans%mod;
    }
    for(int i=cn;i<=n;i++)
    {
        ans=((s(m-1,n,cn+1,ans+a[i],max(cnt,a[i])))%mod+ans)%mod;
    }
    return ans;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int maxa=0;
    bool tag=true;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxa=max(a[i],maxa);
        if(n>3) tag=false;
    }
    if(maxa==1)
    {
        long long ans=0;
        for(int m=3;m<=n;m++)
        {
            //ans+=C^m_n
            long long cnt=1;
            for(int i=n;i>=n-m+1;i--) cnt=(cnt*i)%mod;
            long long cnt2=1;
            for(int i=m;i>=1;i--) cnt2=(cnt2*i)%mod;
            ans=(ans+(cnt/cnt2)%mod)%mod;
        }
        if(n<3) cout<<0<<endl;
        else cout<<ans<<endl;
    }
    else if(tag)
    {
        if(n<3) cout<<0<<endl;
        else
        {
            if(a[1]+a[2]+a[3]>2*maxa) cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
    else
    {
        //$O(n\times n!)$
        long long ans=0;
        for(int m=3;m<=n;m++)
        {
            ans=(ans+s(m,n,m,0,0)%mod)%mod;
        }
        if(n<3) cout<<0<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
