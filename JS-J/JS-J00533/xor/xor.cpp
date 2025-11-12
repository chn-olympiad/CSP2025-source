#include<bits/stdc++.h>
using namespace std;
bool vis[750000];
long ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long n,k;
    long a[750000];
    cin>>n>>k;
    for(long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){
            ans++;
            vis[i]=1;
        }
    }
    for(long i=1;i<=n;i++){
        if(vis[i]!=1){
            long ppl=a[i];
            for(long j=i+1;j<=n;j++){
                if(vis[j]==1){
                    break;
                }else{
                    ppl^=a[j];
                    if(ppl==k){
                        ans++;
                        j=k+1;
                    }
                }
            }
        }
    }cout<<ans;
    return 0;
}
