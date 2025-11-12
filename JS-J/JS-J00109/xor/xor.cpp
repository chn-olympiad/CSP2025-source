#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010][21],s[500010][21],h[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        int tot=1;
        while(x>0){
            a[i][tot]=x%2;
            x/=2;
            tot++;
        }
    }
    for(int i=1;i<=20;i++){
        for(int j=1;j<=n;j++){
            s[j][i]=(s[j-1][i]+a[j][i])%2;
        }
    }
    for(int i=1;i<=n;i++){
        int k=1;
        for(int j=1;j<=20;j++){
            h[i]+=s[i][j]*k;
            k*=2;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(h[i] xor h[j]==k){
                ans++;
                i=j+1;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}