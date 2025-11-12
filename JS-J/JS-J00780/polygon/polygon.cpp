#include<bits/stdc++.h>
using namespace std;
long long int n,ans;
long long int a[5010];
long long int b[5010];
int vis[5010];
void dp(long long int t){
    long long int t1=t+1;
    if(t==0){
        long long int x=0;
        int m=INT_MIN;
        for(int i=1;i<=t;i++){
            x+=b[i];
            if(b[i]>m){
                m=b[i];
            }
        }
        m*=2;
        if(x>m){
            ans++;
        }
        return;
    }
    t--;
    for(int j=1;j<=n;j++){
        if(vis[j]==1){
            continue;
        }
        vis[j]=1;
        b[t1-t]=a[j];
        dp(t);
        t++;
    }
    for(int j=n-t-1;j<=n;j++){
        vis[j]=0;
        b[j]=0;
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
       dp(i);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
}
