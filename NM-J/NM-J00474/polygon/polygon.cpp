#include<bits/stdc++.h>
using namespace std;
int nn,a[5010];
bool light[5010];
int ans=0;
void dfs(int k,int n,int c){
    if(k==nn+1) return;
    if(c==1) light[k]=1;
    if(n>=3&&c==1){
        int maxx=-1;
        long long sum=0;
        for(int i=1;i<=nn;i++){
            if(light[i]==1){
                sum+=a[i];
                maxx=max(maxx,a[i]);
            }
        }
        if(sum>maxx*2) ans++;
    }
    if(light[k+1]==0) dfs(k+1,n+1,1);
    light[k+1]=0;
    dfs(k+1,n,0);
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>nn;
    for(int i=1;i<=nn;i++) cin>>a[i];
    dfs(0,0,0);
    cout<<ans;
    return 0;
    }
