//freopen
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll p=998244353;
int n,m;
string s;
int a[505];
ll ans=1;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]==0)
            n--;
    }
    int op=1;
    if(n<m)
    {
        op=0;
    }
    for(int i=0;i<n;++i)
    {
        if(s[i]=='0')
            op=0;
    }
    if(op==0)
        cout<<0;
    else
    {
        for(int i=1;i<=n;++i)
        {
            ans=(ans*(n-i+1))%p;
        }
        cout<<ans;
    }
    return 0;
}
