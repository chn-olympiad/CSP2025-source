#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=b[i-1]^a[i];
    }
    int now=0,ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j>now;j--){
            if((b[i]^b[j-1])==k){
                now=i;
                ans++;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
