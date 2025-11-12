#include<bits/stdc++.h>
using namespace std;
int a[1000001];
struct tDot
{
    int l;
    int r;
};
tDot t[1000001];
int n,k,cnt;
void solve(int l)
{
    int s=a[l];
    if(s==k)
    {
        t[++cnt]={l,l};
        return ;
    }
    for(int i=l+1;i<=n;i++)
    {
        s^=a[i];
        if(s==k)
        {
            t[++cnt]={l,i};
            return ;
        }
    }
}
bool cmp(tDot a,tDot b)
{
    return a.r<b.r;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        solve(i);
    }
    sort(t+1,t+cnt+1,cmp);
    int ans=0,pres=0;
    for(int i=1;i<=n;i++)
    {
        if(t[i].l>pres)
        {
            ans++;
            pres=t[i].r;
        }
    }
    cout<<ans;
    return 0;
}
