#include<bits/stdc++.h>
using namespace std;
int a[10001];
int s[10001];
bool b[10001];
int ans,n;
void dfs(int dep,int cnt,int pres)
{
    if(cnt>3)
    {
        int maxn=-1,sum=0;
        for(int i=1;i<cnt;i++)
        {
            maxn=max(maxn,s[i]);
            sum+=s[i];
        }
        if(sum>maxn*2)
        {
            ans=(ans+998244353+1)%998244353;
        }
    }
    if(dep>n)return ;
    for(int i=pres+1;i<=n;i++)
    {
        if(!b[i])
        {
            b[i]=1;
            s[cnt]=a[i];
            dfs(dep+1,cnt+1,i);
            b[i]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(1,1,0);
    cout<<ans;
    return 0;
}
