#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,ans;
ll s[5005],x[5005];

void dfs(ll k,ll ind,ll ma,ll sum)
{
    if(k>a)
    {
        if(sum>ma*2)
        {
            ans=(ans+1)%998244353;
            //for (int p=0;p<ind;p++)
            //{
            //    cout<<x[p]<<" ";
            //}
            //cout<<endl;
        }
        return;
    }
    x[ind]=s[k];
    dfs(k+1,ind+1,max(ma,s[k]),sum+s[k]);
    dfs(k+1,ind,ma,sum);
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    const char endl='\n';
    ios::sync_with_stdio(false);
    cin.tie(0);
    //------------
    cin>>a;
    for (int k=1;k<=a;k++)
    {
       cin>>s[k];
    }
    dfs(1,0,0,0);
    cout<<ans;
    return 0;
}
