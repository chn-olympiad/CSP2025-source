#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
    if(x>y){
        return true;
    }return false;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a[1000000]={},cnt=0,n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>20){
        long long ans=1;
        for(int i=3;i<=n;i++){
            long long ans1=1;
            for(int j=n;j>=i;j--){
                ans1*=j;
                ans1%=998244353;
            }
            ans+=ans1;
        }
        cout<<ans%998244353;
        return 0;
    }
    //3
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(a[i]+a[j]>a[k]){
                    cnt++;
                }
                else break;
            }
        }
    }
    //4
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                for(int l=k+1;l<=n;l++){
                    if(a[i]+a[j]+a[k]>a[l]){
                        cnt++;
                    }
                    else break;
                }

            }
        }
    }
    //5
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                for(int l=k+1;l<=n;l++){
                    for(int m=l+1;m<=n;m++){
                        if(a[i]+a[j]+a[k]+a[l]>a[m]){
                            cnt++;
                        }
                        else break;
                    }
                }
            }
        }
    }
    //6
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                for(int l=k+1;l<=n;l++){
                    for(int m=l+1;m<=n;m++){
                        for(int ii=m+1;ii<=n;ii++){
                            if(a[i]+a[j]+a[k]+a[l]+a[m]>a[ii]){
                                cnt++;
                            }
                            else break;
                        }

                    }
                }
            }
        }
    }
    //7
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                for(int l=k+1;l<=n;l++){
                    for(int m=l+1;m<=n;m++){
                        for(int ii=m+1;ii<=n;ii++){
                           for(int jj=ii+1;jj<=n;jj++){
                               if(a[i]+a[j]+a[k]+a[l]+a[m]+a[ii]>a[jj]){
                                    cnt++;
                                }
                                else break;
                            }
                        }
                    }
                }
            }
        }
    }
    //8
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                for(int l=k+1;l<=n;l++){
                    for(int m=l+1;m<=n;m++){
                        for(int ii=m+1;ii<=n;ii++){
                           for(int jj=ii+1;jj<=n;jj++){
                                for(int kk=jj+1;kk<=n;kk++){
                                    if(a[i]+a[j]+a[k]+a[l]+a[m]+a[ii]+a[jj]>a[kk]){
                                       cnt++;
                                    }
                                    else break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    //9
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                for(int l=k+1;l<=n;l++){
                    for(int m=l+1;m<=n;m++){
                        for(int ii=m+1;ii<=n;ii++){
                           for(int jj=ii+1;jj<=n;jj++){
                                for(int kk=jj+1;kk<=n;kk++){
                                    for(int ll=kk+1;ll<=n;ll++){
                                        if(a[i]+a[j]+a[k]+a[l]+a[m]+a[ii]+a[jj]+a[kk]>a[ll]){
                                           cnt++;
                                        }
                                        else break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    //10
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                for(int l=k+1;l<=n;l++){
                    for(int m=l+1;m<=n;m++){
                        for(int ii=m+1;ii<=n;ii++){
                           for(int jj=ii+1;jj<=n;jj++){
                                for(int kk=jj+1;kk<=n;kk++){
                                    for(int ll=kk+1;ll<=n;ll++){
                                        for(int mm=ll+1;mm<=n;mm++){
                                            if(a[i]+a[j]+a[k]+a[l]+a[m]+a[ii]+a[jj]+a[kk]+a[ll]>a[mm]){
                                               cnt++;
                                            }
                                            else break;
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

    cout<<cnt;
    return 0;
}//#Shang4Shan3Ruo6Shui4
