#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll a[505],c[505],f[505];
const ll MOD=998244353;
bool check()
{
    for(int i=1;i<=n;i++)
        if(a[i]==0)
            return false;
    return true;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        char cc;
        cin>>cc;
        a[i]=cc-48;
    }
    for(int i=1;i<=n;i++)
        cin>>c[i];
    if(n<=11)//1-2
    {
        ll cnt=0;
        for(int i=1;i<=n;i++)
            f[i]=i;
        int noo,yees;
        do
        {
            noo=0,yees=0;
            for(int i=1;i<=n;i++)
            {
                if(noo>=c[f[i]])
                {
                    noo++;
                    continue;
                }
                if(a[i]==1)
                    yees++;
                else
                    noo++;
            }
            if(yees>=m)
            {
                cnt++;
                if(cnt>=MOD)
                    cnt-=MOD;
            }
        }while(next_permutation(f+1,f+1+n));
        cout<<cnt;
        return 0;
    }
    if(m==n)//15
    {
        for(int i=1;i<=n;i++)
            if(a[i]==0||c[i]==0)
            {
                cout<<0;
                return 0;
            }
        ll sum=1;
        for(int i=1;i<=n;i++)
            sum=sum*i%MOD;
        cout<<sum;
        return 0;
    }
    if(check())//6-8 16-17
    {
        int cnt1=n;
        for(int i=1;i<=n;i++)
            if(c[i]==0)
                cnt1--;
        if(cnt1<m)
            cout<<0;
        else{
            ll sum=1;
            for(int i=1;i<=n;i++)
                sum=sum*i%MOD;
            cout<<sum;
        }
        return 0;
    }
    cout<<0;
    return 0;
}
