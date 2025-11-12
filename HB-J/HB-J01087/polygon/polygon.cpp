#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int n,flag=1,a[N],pp[N],vis[N];
long long int cnt=0,ans=0,mod=998244353;
bool pd(int num)
{
    int xgm=0,maxx=-1;
    for(int i=1;i<=num;i++)
    {
        xgm+=a[pp[i]];
        if(a[pp[i]]>maxx) maxx=a[pp[i]];
    }
    if(xgm>2*maxx) return 1;
    else return 0;
}
void find(int num)
{
    if(cnt==num)
    {
        if(pd(num)) ans++;
        if(ans>mod) ans-=mod;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0&&i>pp[cnt])
        {
            vis[i]=1;
            pp[++cnt]=i;
            find(num);
            vis[i]=0;
            cnt--;

        }
    }
    return;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>1) flag=0;
    }
    if(flag==1)
    {
        for(long long int i=3;i<=n;i++)
        {
            cnt=1;
            long long int num=1;
            for(long long int j=n;num<=i;j--,num++)
            {
                cnt*=j;
                cnt%=mod;
                cout<<"j="<<j<<" cnt="<<cnt<<" num="<<num<<"\n";
            }
            long long int xy=1;
            for(long long int j=1;j<=i;j++) xy=(xy*j)%mod;
 //           cout<<cnt<<" "<<Pow(cnt,mod-2)<<"\n";
            cnt=cnt/xy;
            cout<<"cnt="<<cnt<<" ";
            ans+=cnt;
            ans%=mod;
            cout<<"ans="<<ans<<"\n";
        }
        ans%=mod;
        cout<<ans;
        return 0;
    }
    for(int i=3;i<=n;i++)
    {
        find(i);
        cnt=0;
        for(int j=1;j<=n;j++) vis[j]=0;
    }
    cout<<ans;
    return 0;
}