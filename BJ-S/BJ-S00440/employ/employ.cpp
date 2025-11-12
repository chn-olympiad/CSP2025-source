#include<bits/stdc++.h>
using namespace std;
const int p=998244353,N=505;
string t;
int a[N],c[N],n,m,box[N],ans;
void dfs(int cur)
{
    int i;
    if(cur==n+1)
    {
        int pass=0,ok=0;
        for(i=1;i<=n;i++)
        {
            // cerr<<a[i]<<" ";
            if(c[a[i]]<=pass||t[i-1]=='0')
            {
                pass++;
            }
            else
            {
                ok++;
            }
        }
        // cerr<<"\n";
        // cerr<<ok<<"\n";
        if(ok>=m)
        {
            ans++;
            ans%=p;
        }
        return ;
    }
    for(i=1;i<=n;i++)
    {
        if(box[i]==0)
        {
            box[i]=1;
            a[cur]=i;
            dfs(cur+1);
            box[i]=0;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    long long i,j,k,l,r,x,y,o,s=1;
    cin>>n>>m;
    cin>>t;
    for(i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    dfs(1);
    cout<<ans<<"\n";
    return 0;
}