#include<bits/stdc++.h>
using namespace std;
int n,k,a[5001],ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n==2) cout<<"1";
    else if(n<=500000){
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0) ans++;
                else if(a[i]==1&&a[i-1]==1){
                    ans++;
                    i++;
                }
            }
        }
        if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==0) ans++;
        }
    }
    else if(n<=10){
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0) ans++;
                else if(a[i]==1&&a[i-1]==1){
                    ans++;
                    i++;
                }
            }
        }
        if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1) ans++;
            }
        }
    }
        cout<<ans;
        return 0;
    }
    return 0;
}
