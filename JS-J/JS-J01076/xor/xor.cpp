#include <bits/stdc++.h>
using namespace std;
int n,k;
int ans=0;
long long a[500001];
bool vis[500001];
bool check(int x,int y){
    if(vis[x]){
        return false;
    }
    long long sum=a[x];
    for(int i=x+1;i<=y;i++){
        if(vis[i]){
            return false;
        }
        sum^=a[i];
    }
    if(sum==k){
        for(int i=x;i<=y;i++){
            vis[i]=true;
        }
        return true;
    }
    return false;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]==k){
            vis[i]=true;
            ans++;
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=(n-i+1);j++){
            if(check(i,i+j-1)){
                ans++;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
