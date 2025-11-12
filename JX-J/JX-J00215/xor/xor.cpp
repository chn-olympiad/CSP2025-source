//n<=985 but wa
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,a[500005],ans,num[500005];
bitset<500005>v1,v2;
vector<int>v;
void dfs(int w,int z){
    if(v1[w]&&v2[z]){
        return ;
    }
    v1[w]=1;
    v2[z]=1;
    if(w==n){
        if(z>ans){
            ans=z;
        }
        return ;
    }
    for(int i=w+1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((num[j]^num[i-1])==k){
                dfs(j,z+1);
            }
        }
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        num[i]=num[i-1]^a[i];
    }
    dfs(0,0);
    cout<<ans<<'\n';
    return 0;
}