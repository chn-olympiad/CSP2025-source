#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005],n,k,a[1005],maxx,ans,minn=9999999,sum,w;
/*void build(int l,int r,int s){
    if(l==r){
        d[s]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,s*2);
    build(mid+1,r,s*2+1);
    d[s]=d[s*2]+d[s*2+1];
}
*/
bool vis[1005],f=1,ff=1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    //build(1,n,1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)f=0;
        if(a[i]!=1&&a[i]!=0)ff=0;
    }
    if(f==1){
        ans=n/2;
        cout<<ans;
        return 0;
    }
    if(ff==1){
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                if(a[i-1]==1)
                ans+=(i-1-sum)/2;
                sum=i;
                ans++;
            }
            else w++;
        }
        if(a[n]==1){
            ans+=(n-sum)/2;
        }
        if(k==0)
        cout<<ans;
        else{
            cout<<w;
        }
        return 0;
    }
    return 0;
}
