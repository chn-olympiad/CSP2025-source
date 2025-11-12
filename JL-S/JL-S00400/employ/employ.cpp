#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,p=998244353;
ll ans;
bool bk[N];
char ch[N];
int n,m,c[N];
void dfs(int op,int cnt,int adr)
{
    if(cnt==m)
    {
        ll res=1,lst=n-op;
        while(lst>0) res=(res*lst)%p,lst--;
        ans+=res;
        return;
    }
    if(op-cnt<=c[adr] && ch[op]=='1') cnt++;
    if(n-op+cnt<m) return;
    if(op==n)
    {
        if(cnt>=m) ans++;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(bk[i]==false)
        {
            bk[i]=true;
            dfs(op+1,cnt,i);
            bk[i]=false;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>ch+1;
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)
    {
        bk[i]=true;
        dfs(1,0,i);
        bk[i]=false;
    }
    printf("%lld\n",ans%p);
    return 0;
}
