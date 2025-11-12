#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,f1=1,f2=1;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)f1=0;
        if(a[i]>1)f2=0;
    }
    if(f1){
        cout<<n/2;
        return 0;
    }
    if(f2){
        int ans=0;
        if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1)ans++;
            }
        }
        else{
            for(int i=1;i<=n;i++){
                if(a[i]==0)ans++;
                if(a[i]==1&&a[i-1]==1){
                    ans++;
                    if(a[i+1]==0)ans++;
                    i++;
                }
            }
        }
        cout<<ans;
        return 0;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            int d=0,f=1;
            for(int l=j;l<=j+i-1;l++){
                if(b[l]){
                    f=0;
                    break;
                }
                d^=a[l];
            }
            if(d==k&&f==1){
                ans++;
                for(int l=j;l<=j+i-1;l++)b[l]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
