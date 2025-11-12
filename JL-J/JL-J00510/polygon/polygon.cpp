#include<bits/stdc++.h>
using namespace std;
const int N=5010,M=998244353;
int a[N];
int n,ans;
void dfs(int z,int mx,int k){
    if(z>mx*2){
        ans++;
        ans%=M;
    }
    int p=mx;
    for(int i=k;i<n;i++){
            mx=max(mx,a[i]);
        dfs(z+a[i],mx,i+1);
        mx=p;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    dfs(a[i],a[i],i+1);
    cout<<ans<<endl;
    return 0;
}
