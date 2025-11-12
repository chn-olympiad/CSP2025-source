#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int a[10005];
int b[10005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1);
    if(n==3){
        if(a[1]+a[2]>a[3]){
            cout<<1%MOD;
            return 0;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    int p=3;
    long long sum=0;
    long long cnt=0;

    b[1]=a[1];
    for(int i=2;i<=n;i++){
        b[i]=a[i]+b[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(a[i]+a[j]>a[k]){
                    cnt++;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                for(int q=k+1;q<=n;q++){
                    if(a[i]+a[j]+a[k]>a[q]){
                        cnt++;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                for(int q=k+1;q<=n;q++){
                    for(int w=q+1;w<=n;w++){
                        if(a[i]+a[j]+a[k]+a[q]>a[w]){
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                for(int q=k+1;q<=n;q++){
                    for(int w=q+1;w<=n;w++){
                        for(int e=w+1;e<=n;e++){
                            if(a[i]+a[j]+a[k]+a[q]+a[w]>a[e]){
                                cnt++;
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                for(int q=k+1;q<=n;q++){
                    for(int w=q+1;w<=n;w++){
                        for(int e=w+1;e<=n;e++){
                            for(int t=e+1;t<=n;t++){
                                if(a[i]+a[j]+a[k]+a[q]+a[w]+a[e]>a[t]){
                                    cnt++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                for(int q=k+1;q<=n;q++){
                    for(int w=q+1;w<=n;w++){
                        for(int e=w+1;e<=n;e++){
                            for(int t=e+1;t<=n;t++){
                                for(int y=t+1;y<=n;y++){
                                    if(a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[t]>a[y]){
                                        cnt++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                for(int q=k+1;q<=n;q++){
                    for(int w=q+1;w<=n;w++){
                        for(int e=w+1;e<=n;e++){
                            for(int t=e+1;t<=n;t++){
                                for(int y=t+1;y<=n;y++){
                                    for(int u=y+1;u<=n;u++){
                                        if(a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[t]+a[y]>a[u]){
                                            cnt++;
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
    if(n==10){
        if(b[n-1]>a[n]){
            cnt++;
        }
    }
    cout<<cnt%MOD;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
