#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],vis[5005];
long long ans;
int mp1[5005],mp2;
void dfs(int x){
    if (x>3){
        int sum=0,maxn=-0x3f3f3f3f3f;
        for (int i=1;i<x;i++){
            sum+=b[i];
            maxn=max(maxn,b[i]);
        }
        if (sum>2*maxn){
            for (int i=1;i<x;i++){
                if (mp1[a[i]]>1){
                    mp2++;
                    break;
                }
            }

            ans++;
            ans%=998244353;
        }
    }
    for (int i=1;i<=n;i++){
        if (!vis[i]&&a[i]>=b[x-1]){
            b[x]=a[i];
            vis[i]=1;
            dfs(x+1);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if (n<3){
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        cout<<0<<endl;
        return 0;
    }else if (n==3){
        int c,d,e;
        cin>>c>>d>>e;
        int maxn=max(c,max(d,e));
        if (c+d+e<2*maxn){
            cout<<0;
        }else cout<<1;
        return 0;
    }
    for (int i=1;i<=n;i++){
        cin>>a[i];
        mp1[a[i]]++;
    }
    dfs(1);
    cout<<ans-mp2/2+1;
    return 0;
}
