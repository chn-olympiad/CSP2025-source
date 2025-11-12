#include<bits/stdc++.h>
using namespace std;
int n;
int m;
string s;
int c;
long long ans=1,sum=0;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>s;
    if(m>n)cout<<0;
    for(int i=1;i<=n;i++)
    {
        cin>>c;
        sum+=(c==0);
    }
    int k=n-sum;
    if(k<m)cout<<0;
    for(int i=1;i<=k;i++)
    {
        ans=(ans*i)%998244353;
    }
    cout<<ans;
    return 0;
}
