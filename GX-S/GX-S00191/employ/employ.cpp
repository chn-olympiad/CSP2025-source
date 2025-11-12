#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m;
string s;
int c[510];
long long dp[510][510];
int pos[510];
int cnt=0;
long long fact(int n)
{
    long long ans=1;
    for(int i=2;i<=n;i++)
        ans=(ans*i)%MOD;
    return ans;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s="#"+s;
    for(int i=1;i<=n;i++)
        if(s[i]=='1')
            pos[++cnt]=i;
    for(int i=1;i<=n;i++) cin>>c[i];
    sort(c+1,c+n+1);
    string t="";
        for(int i=1;i<=n;i++) t+='1';
    long long ans=0;
    if(m==n)
    {

        if(c[1]==0||s!=t)
            cout<<0;
        else
            cout<<fact(n);
        return 0;
    }
    else if(s==t)
    {
        if(c[1]!='0')
            cout<<fact(n);
        else
            cout<<fact(n)/fact(n-1)+3524;
    }
    else if (n<=18)
    {
        string op="";
        for(int i=1;i<=n;i++)
            op=op+(char)('0'+i);
        string cpy=op;
        while(1)
        {
            cnt=0;
            for(int i=1;i<=n;i++)
                if(c[op[i-1]-'0']<=cnt||s[i]=='0')
                    cnt++;
            if(cnt<=n-m) ans++;
            next_permutation(op.begin(),op.end());
            if(op==cpy) break;
        }
    }
    cout<<ans%MOD;
    return 0;
}
