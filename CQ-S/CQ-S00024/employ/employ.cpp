#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=15;
const int mod=998244353;
int n,m,c[N],pos[N],ans;
string s;
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>s;
    s=" "+s;
    for(int i=1;i<=n;i++)
    {
        pos[i]=i;
        cin>>c[i];
    }
    do
    {
        int cnt=0,tot=0;
        for(int i=1;i<=n;i++)
        {
            int now=pos[i];
            if(s[i]=='0'||tot>=c[now])
                tot++;
            else
                cnt++;
        }            
        if(cnt>=m)
            ans=(ans+1)%mod;
    } 
    while(next_permutation(pos+1,pos+n+1));
    cout<<ans;
    return 0;
}