#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],cnt;
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n==3){
        if(a[1]+a[2]>a[3]) cout<<1;
        else cout<<0;
    }
    if(n==4){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k])) cnt++;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                        for(int z=k+1;z<=n;z++){
                            if(a[i]+a[j]+a[k]+a[z]>2*max(max(max(a[i],a[j]),a[k]),a[z])) cnt++;
                        }
                }
            }
        }
        cout<<cnt;
    }
    if(n==5){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k])) cnt++;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                        for(int z=k+1;z<=n;z++){
                            if(a[i]+a[j]+a[k]+a[z]>2*max(max(max(a[i],a[j]),a[k]),a[z])) cnt++;
                        }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                        for(int z=k+1;z<=n;z++){
                                for(int l=z+1;l<=n;l++){
                                    if(a[i]+a[j]+a[k]+a[z]+a[l]>2*max(max(max(max(a[i],a[j]),a[k]),a[z]),a[l])) cnt++;
                                }

                        }
                }
            }
        }
        cout<<cnt;
    }
    return 0;
}
