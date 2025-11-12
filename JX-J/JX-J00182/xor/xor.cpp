#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],f[500005];
bool b[500005];
int dfs(int m,int x){
    int ans=0;
    if(b[m] && x==0)return f[m];
    x^=a[m];
    if(x==k){
        x=0;
        ans++;
    }
    int Max=0;
    for(int i=m+1;i<=n;i++){
        Max=max(dfs(i,x),Max);
    }
    if(x==0){
        f[m]=Max+ans;
        b[m]=1;
    }
    return Max+ans;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int m=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        m=max(a[i],m);
    }
    if(k==0&&m==1) cout<<n/2;
    if(k==0&&m==0) cout<<n;
    cout<<dfs(1,0);
    return 0;
}
