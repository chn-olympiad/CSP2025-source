#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5050;
const int mod=998244353;
int n,ans,arr[N],jc[N];
string dtob(int n)
{
    string res="";
    while(n>0)
    {
        res.push_back(char(n%2)+'0');
        n/=2;
    }
    reverse(res.begin(),res.end());
    int len=(::n);
    while(res.size()<len)
    {
        res='0'+res;
    }
    return res;
}
void jcs(int n)
{
    jc[0]=jc[1]=1;
    for(int i=2;i<=n;i++)
    {
        jc[i]=jc[i-1]*i;
    }
}
bool check(string str)
{
    int maxn=-1;
    int sum=0;
    int cnt=0;
    for(int i=0;i<(int)str.size();i++)
    {
        if(str[i]=='1')
        {
            cnt++;
            maxn=max(maxn,arr[i+1]);
            sum+=arr[i+1];
        }
    }
    return (cnt>=3) && (sum>2*maxn);
}
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    jcs(N);
    /*
    for(int i=1;i<=N;i++)
    {
        cout<<jc[i]<<' ';
    }*/
    if(n<3)
    {
        cout<<0<<'\n';
        return 0;
    }
    if(n>20)
    {
        for(int i=3;i<=n;i++)
        {
            ans+=jc[n]/(jc[n-i]*jc[i]);
            ans%=mod;
        }
        cout<<ans<<'\n';
        return 0;
    }
    for(int k=1;k<=(1<<n)-1;k++)
    {
        string str=dtob(k);
        //cout<<str<<'\n';
        if(check(str))
        {
            //cout<<str<<'\n';
            ans++;
            ans%=mod;
        }
    }cout<<ans%mod<<'\n';
    return 0;
}


//9:49 xia ku le
//9:51 zhe ti O(2^n) you 40pts?
//10:06 tiao shi wan cheng
//10:09 +40pts , chang shi pin hao fen
//10:11 zu he shu xue,mei jiu le
//10:14 hui qu xie T3 ba
//10:40 kan kan pin hao fen
//10:48 zhao dao shi zi le
//10:52 bu xing , bu neng zhi jie cheng
//10:53 hai yao gao jing chu,bai le
