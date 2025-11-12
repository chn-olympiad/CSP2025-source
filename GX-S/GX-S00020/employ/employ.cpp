#include <bits/stdc++.h>
using namespace std;

const int INF=998244353;
int a[501],num[501];

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++)   cin>>a[i];
    int fg=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            fg=1;
            break;
        }
    }
    if(fg==1 && m==n)   cout<<0<<endl;
    long long ans=0;
    int x=0;
    for(int i=1;i<=n;i++)
    {
        num[i]=i;
        if(x>=a[i]|| s[i-1]=='0') x++;
    }
    if(m<=n-x)  ans++;
    while(next_permutation(num+1,num+1+n))
    {
        x=0;
        for(int i=1;i<=n;i++)
        {
            if(x>=a[num[i]] || s[i-1]=='0') x++;
        }
        if(m<=n-x)  ans++;
        ans%=INF;
    }
    cout<<ans<<endl;
    return 0;
}
