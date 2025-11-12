#include<bits/stdc++.h>
using namespace std;
int a[5001];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    sort(a+1,a+n+1);
    int sum=0;
    if(n==3){

        for(int i=1;i<=n;i++){
            sum+=a[i];
        }
        if(sum>2*a[n])cout<<1;
        else cout<<0;
        return 0;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                sum=0;
                sum=a[i]+a[j]+a[k];
                if(sum>2*a[k]){
                    ans++;
                }

            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                    for(int aa=k+1;aa<=n;aa++){
                sum=0;
                sum=a[i]+a[j]+a[k]+a[aa];
                if(sum>2*a[aa]){
                    ans++;
                }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                    for(int aa=k+1;aa<=n;aa++){
                            for(int aaa=aa+1;aaa<=n;aaa++){
                sum=0;
                sum=a[i]+a[j]+a[k]+a[aa]+a[aaa];
                if(sum>2*a[aaa]){
                    ans++;
                }
                }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                    for(int aa=k+1;aa<=n;aa++){
                            for(int aaa=aa+1;aaa<=n;aaa++){
                                    for(int aaaa=aaa+1;aaaa<=n;aaaa++){
                sum=0;
                sum=a[i]+a[j]+a[k]+a[aa]+a[aaa]+a[aaaa];
                if(sum>2*a[aaaa]){
                    ans++;
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
                    for(int aa=k+1;aa<=n;aa++){
                            for(int aaa=aa+1;aaa<=n;aaa++){
                                    for(int aaaa=aaa+1;aaaa<=n;aaaa++){
                                            for(int cc=aaaa+1;cc<=n;cc++){
                sum=0;
                sum=a[i]+a[j]+a[k]+a[aa]+a[aaa]+a[aaaa]+a[cc];
                if(sum>2*a[cc]){
                    ans++;
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
                    for(int aa=k+1;aa<=n;aa++){
                            for(int aaa=aa+1;aaa<=n;aaa++){
                                    for(int aaaa=aaa+1;aaaa<=n;aaaa++){
                                            for(int cc=aaaa+1;cc<=n;cc++){
                                                    for(int ii=cc+1;ii<=n;ii++){
                sum=0;
                sum=a[i]+a[j]+a[k]+a[aa]+a[aaa]+a[aaaa]+a[cc]+a[ii];
                if(sum>2*a[ii]){
                    ans++;
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
                    for(int aa=k+1;aa<=n;aa++){
                            for(int aaa=aa+1;aaa<=n;aaa++){
                                    for(int aaaa=aaa+1;aaaa<=n;aaaa++){
                                            for(int cc=aaaa+1;cc<=n;cc++){
                                                    for(int ii=cc+1;ii<=n;ii++){
                                                            for(int jj=ii+1;jj<=n;jj++){
                sum=0;
                sum=a[i]+a[j]+a[k]+a[aa]+a[aaa]+a[aaaa]+a[cc]+a[ii]+a[jj];
                if(sum>2*a[jj]){
                    ans++;
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
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                    for(int aa=k+1;aa<=n;aa++){
                            for(int aaa=aa+1;aaa<=n;aaa++){
                                    for(int aaaa=aaa+1;aaaa<=n;aaaa++){
                                            for(int cc=aaaa+1;cc<=n;cc++){
                                                    for(int ii=cc+1;ii<=n;ii++){
                                                            for(int jj=ii+1;jj<=n;jj++){
                                                                    for(int kk=jj+1;kk<=n;kk++){
                sum=0;
                sum=a[i]+a[j]+a[k]+a[aa]+a[aaa]+a[aaaa]+a[cc]+a[ii]+a[jj]+a[kk];
                if(sum>2*a[kk]){
                    ans++;
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
    cout<<ans;
}
