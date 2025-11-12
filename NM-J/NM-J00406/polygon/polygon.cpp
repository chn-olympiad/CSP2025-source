#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int modd=998244353;
int n,a[6000],ans,vis[6000],i,l[6000];
void ho(){
    int u=0,s=0;
    for (int j=1;j<=i;j++){
        u+=a[l[j]];
        s=max(a[l[j]],s);
    }
    if (u>2*s){
        ans++;
        ans%=modd;
    }
}
void f(int k){
    if (k>i){
        ho();
        return;
    }
    for (int j=1;j<=n;j++){
        if (vis[j]==0&&j>=l[k-1]){
            vis[j]=1;
            l[k]=j;
            f(k+1);
            vis[j]=0;
        }
    }
}

signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (i=3;i<=n;i++){
        for (int j=1;j<=i+2;j++){
            vis[j]=0;
            l[j]=0;
        }
        f(1);
    }
    cout<<ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
