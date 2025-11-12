#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans=0;
    cin>>n>>k;
    int s[n+1];
    int x;
    s[0]=0;
    for(int i=1;i<=n;i++){
        cin>>x;
        s[i]=s[i-1]^x;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((s[j]^s[i-1])==k){
                ans++;
                i=j;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
