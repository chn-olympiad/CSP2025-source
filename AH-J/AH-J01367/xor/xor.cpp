#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,k,a[maxn],sum[maxn];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    int i=1,j=1,ans=0;
    while(j<=n){
        for(int c=i;c<=j;++c){
            if((sum[j]^sum[c-1])==k){
                ++ans;
                i=j+1;
                break;
            }
        }
        ++j;
    }
    cout<<ans<<endl;
    return 0;
}