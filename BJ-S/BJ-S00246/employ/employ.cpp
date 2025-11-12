#include<bits/stdc++.h>
using namespace std;
const int N=505,MOD=998244353;
int n,m,a[N],r;
bool flag;
long long ans=1;
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    r=n;
    for(int i=1;i<=n;i++)
    {
        if(s[i-1]=='0')
        {
            flag=1;
        }
        cin>>a[i];
        if(a[i]==0)
        {
            r--;
        }
    }
    if(r<m)
    {
        cout<<0;
        return 0;
    }
    if(flag==0)
    {
        for(int i=2;i<=n;i++)
        {
            ans*=i;
            ans%=MOD;
        }
        cout<<ans;
        return 0;
    }
    cout<<0;
    return 0;
}
