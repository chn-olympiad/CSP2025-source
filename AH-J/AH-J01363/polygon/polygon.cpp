#include<bits/stdc++.h>
using namespace std;
int n,sum;
const int mod=998244353;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }if(n>100){
        cout<<0;
    }sort(a+1,a+n+1);
    if(n>=3){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if(a[i]+a[j]+a[k]>a[k]*2){
                        sum++;
                        sum%=mod;
                    }else{
                        break;
                    }
                }
            }
        }
    }if(n>=4){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int l=k+1;l<=n;l++){
                        if(a[i]+a[j]+a[k]+a[l]>a[l]*2){
                            sum++;
                            sum%=mod;
                        }else{
                            break;
                        }
                    }
                }
            }
        }
    }if(n>=5){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int l=k+1;l<=n;l++){
                        for(int m=l+1;m<=n;m++){
                            if(a[i]+a[j]+a[k]+a[l]+a[m]>a[m]*2){
                                sum++;
                                sum%=mod;
                            }else{
                                break;
                            }
                        }
                    }
                }
            }
        }
    }if(n>=6){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int l=k+1;l<=n;l++){
                        for(int m=l+1;m<=n;m++){
                            for(int I=m+1;I<=n;I++){
                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[I]>a[I]*2){
                                    sum++;
                                    sum%=mod;
                                }else{
                                    break;
                                }
                            }

                        }
                    }
                }
            }
        }
    }if(n>=7){
         for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int l=k+1;l<=n;l++){
                        for(int m=l+1;m<=n;m++){
                            for(int I=m+1;I<=n;I++){
                                if(a[i]+a[j]+a[k]+a[l]+a[m]+a[I]>a[I]*2){
                                    sum++;
                                    sum%=mod;
                                }else{
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }if(n>=8){
         for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int l=k+1;l<=n;l++){
                        for(int m=l+1;m<=n;m++){
                            for(int I=m+1;I<=n;I++){
                                for(int J=I+1;J<=n;J++){
                                    if(a[i]+a[j]+a[k]+a[l]+a[m]+a[I]+a[J]>a[J]*2){
                                        sum++;
                                        sum%=mod;
                                    }else{
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }if(n>=9){
         for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int l=k+1;l<=n;l++){
                        for(int m=l+1;m<=n;m++){
                            for(int I=m+1;I<=n;I++){
                                for(int J=I+1;J<=n;J++){
                                    for(int K=J+1;K<=n;K++){
                                        if(a[i]+a[j]+a[k]+a[l]+a[m]+a[I]+a[J]+a[K]>a[K]*2){
                                            sum++;
                                            sum%=mod;
                                        }else{
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }if(n>=10){
         for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int l=k+1;l<=n;l++){
                        for(int m=l+1;m<=n;m++){
                            for(int I=m+1;I<=n;I++){
                                for(int J=I+1;J<=n;J++){
                                    for(int K=J+1;K<=n;K++){
                                        for(int L=K+1;L<=n;L++){
                                            if(a[i]+a[j]+a[k]+a[l]+a[m]+a[I]+a[J]+a[K]+a[L]>a[L]*2){
                                                sum++;
                                                sum%=mod;
                                            }else{
                                                break;
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
    }cout<<sum;
    return 0;
}

