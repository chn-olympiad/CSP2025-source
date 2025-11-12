#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[655555];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    unsigned long long ddp[n+5][n+5];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=i;k<=j;k++){
                if(k==i) ddp[i][j]=a[k];
                else ddp[i][j]^=a[k];
            }
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(ddp[i][j]==k){
                ans++;
                i=j+1;
                j=i;
            }
        }
    }
    cout<<ans;
    return 0;
}
