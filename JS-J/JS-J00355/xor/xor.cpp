#include<bits/stdc++.h>
using namespace std;
int a[1011011];
int p[1011111];
int r[1010101];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=2&&k==0){
        int ans=0;
        if(n==1){
            cout<<0;
            return 0;
        }
        if(a[1]==0)ans++;
        if(a[2]==0)ans++;
        if(a[1]!=0&&a[2]!=0&&a[1]^a[2]==0)ans=1;
        cout<<ans;
        return 0;
    }
    if(k<=1&&n>1000){
        for(int i=1;i<=n;i++){
            if(a[i]==n)ans++;
        }
        if(k==0){
            for(int i=1;i<n;i++){
                if(a[i]==1&&a[i+1]==1)ans++;
            }
        }
        int x=0^0;
        cout<<ans;
        return 0;
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n-j+1;i++){
            int x=0;
            for(int k=i;k<=i+j-1;k++){
                if(p[k]==1){
                    x=-1;
                    break;
                }
                x=x^a[k];

            }
            if(x==k){
                ans++;
                for(int k=i;k<=i+j-1;k++)p[k]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
