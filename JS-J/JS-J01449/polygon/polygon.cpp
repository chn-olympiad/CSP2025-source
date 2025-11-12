#include<bits/stdc++.h>
using namespace std;
long long a[100006],ans,t[100006],vis[100006],nn,tmp[100006];
void print(int n){
    for(int i=1;i<=n;i++){
        cout<<tmp[i]<<" ";
    }
    cout<<endl;
    return;
}
void dfs(int cur,int n,int tot){
    if(tot==n){
        long long maxn=-1,sum=0;
        for(int i=1;i<=tot;i++){
            maxn=max(maxn,t[i]);
            sum+=t[i];
        }
        if(sum>maxn*2){
            ans++;
            // print(n);
            // cout<<sum<<" "<<maxn<<endl;
        }
        return;
    }
    for(int i=cur+1;i<=nn;i++){
        if(!vis[i]){
            vis[i]=1;
            t[tot+1]=a[i];
            tmp[tot+1]=i;

            dfs(i,n,tot+1);

            t[tot+1]=0;
            tmp[tot+1]=0;
            vis[i]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>nn;
    long long max1=-1;
    for(int i=1;i<=nn;i++){
        cin>>a[i];
        max1=max(max1,a[i]);
    }
    sort(a+1,a+nn+1);
    // if(max1==1&&nn>20){
        
    // }
    // else{
    for(int i=3;i<=nn;i++){
        for(int j=1;j<=nn-i+1;j++){
            t[1]=a[j];
            vis[j]=1;
            tmp[1]=j;
            dfs(j,i,1);
            t[1]=0;
            tmp[1]=0;
            vis[j]=0;
        }
    }
    // }
    cout<<ans;
    return 0;
}