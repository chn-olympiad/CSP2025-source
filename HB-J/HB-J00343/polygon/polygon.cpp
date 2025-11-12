#include<bits/stdc++.h>
using namespace std;

const int N=500;
int n,a[N];
bool vis[N];
int m,sum,maxn=-9999;
int ans;

void dfs(int cnt){
    m=0,sum=0,maxn=0;
    if(cnt==n+1){
        for(int i=1;i<=n;i++){
            if(vis[i]){
                m++;
                sum+=a[i];
                if(a[i]>maxn){
                    maxn=a[i];
                }
            }
        }
        if(m>=3&&sum>2*maxn){
            ans++;
        }
        return ;
    }
    for(int i=1;i>=0;i--){
        vis[cnt]=i;
        dfs(++cnt);
        cnt--;
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);
    cout<<ans%998244353;
    return 0;
}
