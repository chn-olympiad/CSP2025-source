# include <bits/stdc++.h>

using namespace std;

const int N=5e5+10;
typedef long long ll ;
ll a[N];
ll dp[N];
ll n,k;

ll _xor(ll a,ll b)
{
    ll sum=0;
    string s;
    while(a>0 || b>0)
    {
        if(a%2==b%2)
            s+='1';
        else
            s+='0';
        a/=2;
        b/=2;
    }
    for(int i=s.size()-1;i>=0;i--)
    {
        if(i==0 && s[i]!='0')
            sum+=1;
        else
            sum=sum+(s[i]-'0')*pow(2,i);
    }
    return sum;
}

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        cin >> a[i] ;
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=k;j>=0;j--)
        {
            if(j>=_xor(a[i],a[i-1]))
                dp[j]=max(dp[j],dp[j-_xor(a[i],a[i-1])]+1);
        }
    }
    cout << dp[k] << endl;
    return 0;
}
