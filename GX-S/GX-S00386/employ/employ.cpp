#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
string s;
int n,c[505],m,p[505],x,a[505],q,sum=1,f;
long long ans,N;
long long calc(int k)
{
    long long res=1;
    while(k)
    {
        res*=k;
        res%=mod;
        --k;
    }
    return res;
}
bool check()
{
    int k=0,cnt=0;
    for(int i=1;i<=n;++i)
    {
        if(cnt>=a[i])
            ++cnt;
        else if(s[i-1]=='0')
            ++cnt;
        else
            ++k;
    }
    //cout<<cnt<<" ";
    if(k>=m)
        return 1;
    return 0;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<s.length();++i)
    {
        if(s[i]=='0')
            f=1;
    }
    //for(int i=0;i<n;++i)
        //p[i]=p[i-1]+1-(s[i]-'0');

    for(int i=1;i<=n;++i)
    {
        cin>>x;
        c[x]++;
    }
    if(f==0)
    {
        cout<<calc((n-c[0]));
        return 0;
    }
    if(c[0])
        sum*=calc(c[0]);
    sum%=mod;
    for(int i=1;i<=n;++i)
    {
        if(c[i])
            sum*=calc(c[i]);
        sum%=mod;
        for(int j=1;j<=c[i];++j)
            a[++q]=i;
    }
    N=calc(n)-(sum-1)*n;
    for(int j=1;j<=N;++j)
    {
        //for(int i=1;i<=n;++i)
                //cout<<a[i]<<" ";
        if(check())
        {
            ans+=sum;ans%=mod;
            next_permutation(a+1,a+n+1);
        }
        //else
            //break;
    }
    cout<<ans;
    return 0;
}

