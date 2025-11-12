#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,ans;
long long a[5005],tot[5005];
bool h[5005];
bool cmp(long long a,long long b) { return a>b; }
//long long cnt;
void choose(long long x)
{
    if(x>n)
    {
        long long maxn=0,sum=0;
        for(long long i=1;i<=n;i++)
        {
            if(h[i])
            {
                sum+=a[i];
                maxn=max(maxn,a[i]);
            }
        }
        if(sum>maxn*2)
        {
            ans++;
            ans%=mod;
        }
        return ;
    }
    h[x]=0;
    choose(x+1);
    h[x]=1;
    choose(x+1);
}
long long quick_pow(long long x)
{
    if(x==1) return 2;
    long long ans1=quick_pow(x/2)%mod;
    ans1=ans1*ans1%mod;
    if(x%2==1) ans1*=2;
    return ans1;
}
void choose1(long long x,long long maxn,long long sum,long long num)
{
    //cnt++;
   //cout<<"\n"<<x<<" "<<maxn<<" "<<sum;
    if(x>n)
    {
        if(num>2)
        {
            ans++;
            //cout<<1;
        }
        //else cout<<0;
        //cout<<"\n";
        return ;
    }
    //cout<<"\n";
    if(3-num>n-x+1) return;
    if(num==0)
    {
        choose1(x+1,0,0,0);
        choose1(x+1,a[x],a[x],1);

        return;
    }
    if(sum+tot[x]<=maxn*2) return;
    if(sum>maxn*2)
    {
        ans+=quick_pow(n-x+1);
        //cout<<"\n"<<x<<" "<<maxn<<" "<<sum;
        //cout<<"\n"<<pow(2,n-x+1)<<"\n";
        ans%=mod;
        return;
    }
    //cout<<"\n";
    choose1(x+1,maxn,sum+a[x],num+1);
    choose1(x+1,maxn,sum,num);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++) cin>>a[i];
    bool te=1;
    for(long long i=1;i<=n;i++)
    {
        if(a[i]!=1)
        {
            te=0;
            break;
        }
    }
    if(te)
    {
        cout<<quick_pow(n)-1-n-n*(n-1)/2;
        return 0;
    }
    if(n<=20) choose(1);
    else
    {
        sort(a+1,a+n+1,cmp);
        for(long long i=n;i>=1;i--)
        {
            tot[i]=a[i]+tot[i+1];
            if(tot[i]<0)
            {
                cout<<"error";
                return 0;
            }
        }
        choose1(1,0,0,0);
        ans-=1;
    }
    cout<<ans;//<<" "<<cnt;

    return 0;
}
