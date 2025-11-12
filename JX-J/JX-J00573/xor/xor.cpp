#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],pre[500005],ans;
bool vis[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1) cout<<(a[1]==k);
    else if(n==2)
    {
        if(a[1]==k&&a[2]==k) cout<<'2';
        else if((a[1]^a[2])==k||a[1]==k||a[2]==k) cout<<'1';
        else cout<<'0';
    }
    else
    {
        partial_sum(a+1,a+n+1,pre+1,[](const int& x,const int& y){return x^y;});
        for(int l=1;l<=n;l++)
        {
            if(vis[l]) continue;
            for(int r=l;r<=n;r++)
            {
                if((pre[r]^pre[l-1])==k)
                {
                    fill(vis+l,vis+r+1,true);
                    l=r,ans++;
                    break;
                }
            }
        }
        cout<<ans;
    }
    //What a 78 problem!Does Coin Collecting Foundation have any egg?
    return 0;
}
