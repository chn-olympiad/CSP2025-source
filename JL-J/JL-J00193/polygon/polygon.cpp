#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        int max3=0;
        int s3=a[1]+a[2]+a[3];
        for(int k=1;k<=3;k++){
            if(a[k]>max3) max3=a[k];
        }
        if(s3>max3*2){
            cout<<1;
            return 0;
        }else{
            cout<<0;
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+2;j<=n;j++){
            int maxn=0;
            int s=0;
            for(int k=i;k<=j;k++){
                if(a[k]>maxn) maxn=a[k];
                s+=a[k];
            }
            if(s>(maxn*2)){
                ans++;
            }
        }
    }
    cout<<ans%998244353;
    return 0;
}
