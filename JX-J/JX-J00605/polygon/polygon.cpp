#include<bits/stdc++.h>
using namespace std;
int a[5050];
int n;
int num,ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    num=3;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                int sum=a[i]+a[j]+a[k];
                int cj=2*a[k];
                if(sum>cj){
                    ans++;
                    ans%=998244353;
                }
            }
        }
    }
    if(num==n){
        printf("%d",ans);
        return 0;
    }
    num=4;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                for(int q=k+1;q<=n;q++){
                    int sum=a[i]+a[j]+a[k]+a[q];
                    int cj=2*a[q];
                    if(sum>cj){
                        ans++;
                        ans%=998244353;
                    }
                }
            }
        }
    }
    if(num==n){
        printf("%d",ans);
        return 0;
    }
    num=5;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                for(int q=k+1;q<=n;q++){
                    for(int w=q+1;w<=n;w++){
                        int sum=a[i]+a[j]+a[k]+a[q]+a[w];
                        int cj=2*a[w];
                        if(sum>cj){
                            ans++;
                            ans%=998244353;
                        }
                    }
                }
            }
        }
    }
    if(num==n){
        printf("%d",ans);
        return 0;
    }
    num=6;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                for(int q=k+1;q<=n;q++){
                    for(int w=q+1;w<=n;w++){
                        for(int e=w+1;e<=n;e++){
                            int sum=a[i]+a[j]+a[k]+a[q]+a[w]+a[e];
                            int cj=2*a[e];
                            if(sum>cj){
                                ans++;
                                ans%=998244353;
                            }
                        }
                    }
                }
            }
        }
    }
    if(num==n){
        printf("%d",ans);
        return 0;
    }
    num=7;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                for(int q=k+1;q<=n;q++){
                    for(int w=q+1;w<=n;w++){
                        for(int e=w+1;e<=n;e++){
                            for(int r=e+1;r<=n;r++){
                                int sum=a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r];
                                int cj=a[r];
                                if(sum>cj){
                                    ans++;
                                    ans%=998244353;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(num==n){
        printf("%d",ans);
        return 0;
    }
    num=8;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                for(int q=k+1;q<=n;q++){
                    for(int w=q+1;w<=n;w++){
                        for(int e=w+1;e<=n;e++){
                            for(int r=e+1;r<=n;r++){
                                for(int t=r+1;t<=n;t++){
                                    int sum=a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t];
                                    int cj=2*a[t];
                                    if(sum>cj){
                                        ans++;
                                        ans%=998244353;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(num==n){
        printf("%d",ans);
        return 0;
    }
    num=9;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                for(int q=k+1;q<=n;q++){
                    for(int w=q+1;w<=n;w++){
                        for(int e=w+1;e<=n;e++){
                            for(int r=e+1;r<=n;r++){
                                for(int t=r+1;t<=n;t++){
                                    for(int y=t+1;y<=n;y++){
                                        int sum=a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y];
                                        int cj=2*a[y];
                                        if(sum>cj){
                                            ans++;
                                            ans%=998244353;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(num==n){
        printf("%d",ans);
        return 0;
    }
    num=10;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                for(int q=k+1;q<=n;q++){
                    for(int w=q+1;w<=n;w++){
                        for(int e=w+1;e<=n;e++){
                            for(int r=e+1;r<=n;r++){
                                for(int t=r+1;t<=n;t++){
                                    for(int y=t+1;y<=n;y++){
                                        for(int u=y+1;u<=n;u++){
                                            int sum=a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u];
                                            int cj=2*a[u];
                                            if(sum>cj){
                                                ans++;
                                                ans%=998244353;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
