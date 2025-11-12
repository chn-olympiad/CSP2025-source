#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string s;
int c[505];
int cc[505];
int a[505];
void solveA()
{
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        ans*=i;
        ans%=mod;
    }
    cout<<ans<<endl;
}
void solvem()
{

    sort(c+1,c+n+1);
    int id=2147483647;
    for(int i=0;i<s.size();i++)
    {
        //cout<<s[i]<<" ";
        if(s[i]=='1')
        {
            id=i;
            break;
        }
    }
    int t;
    for(int i=1;i<=n;i++)
    {
        cout<<id<<" "<<c[i]<<endl;
        if(c[i]>id)
        {
            t=i;
            break;
        }
    }
    //cout<<t<<endl;
    int ans=n-t+1;
    for(int i=1;i<n;i++)
    {
        ans*=i;
        ans%=mod;
    }
    cout<<ans<<endl;
}
void solve()
{
    int ans=0;
    for(int i=1;i<=n;i++)
        a[i]=i;
    do
    {
        for(int i=1;i<=n;i++)
            cc[i]=c[a[i]];
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(cc[i]<=cnt || s[i-1]=='0')
                cnt++;
        }
        if(n-cnt>=m)
        {
            ans++;
            ans%=mod;
            //for(int i=1;i<=n;i++)
            //    cout<<cc[i]<<" ";
            //cout<<endl;
        }
    }
    while(next_permutation(a+1,a+n+1));
    cout<<ans%mod<<endl;
    return ;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    bool f=true;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='1')
        {
            f=false;
            break;
        }
    }
    if(m==1)
        solvem();
    else if(f)
        solveA();
    else
        solve();
    return 0;
}
