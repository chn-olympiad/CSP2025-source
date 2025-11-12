#include<bits/stdc++.h>
using namespace std;
int ans;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    if(k>0){
        for(int i=0;i<=n;i++){
            if(a[i]>=1){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
