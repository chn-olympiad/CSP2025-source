#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    int a[10001];
    int js;
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n>=3){
        for(int i=1;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                for(int k=i+2;i<=n;k++){
                    if(a[i]+a[j]>a[k]){
                        ans++;
                    }
                }
            }
        }
    }
    if(n>=4){
        for(int i=1;i<=n-3;i++){
            for(int j=i+1;j<=n-2;j++){
                for(int k=i+2;i<=n-1;k++){
                    for(int l=i+3;l<=n;l++){
                        if(a[i]+a[j]+a[k]>a[l]){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    if(n>=5){
        for(int i=1;i<=n-4;i++){
            for(int j=i+1;j<=n-3;j++){
                for(int k=i+2;i<=n-2;k++){
                    for(int l=i+3;l<=n-1;l++){
                        for(int y=i+4;y<=n;y++){
                            if(a[i]+a[j]+a[k]+a[l]>a[y]){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
