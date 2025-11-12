#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,s,z=0,w=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a[50005];
        int b[50005];
        int c[50005];
        int wei[5];
        int sum[50005];
        int sum2[50005];
        cin>>s;
        for(int j=1;j<=s;j++){
            cin>>a[j]>>b[j]>>c[j];
            if(a[j]==0&&b[j]==0){
                sum[j]=c[j];

                wei[3]+=1;
                sum2[j]=0;

            } if(a[j]==0){
                if(b[j]>=c[j]){
                    sum[j]=b[j];
                    wei[2]+=1;
                    sum2[j]=c[j];
                }else{
                    sum[j]=c[j];
                    wei[3]+=1;
                    sum2[j]=b[j];
                }
            }else if(b[j]==0){
                if(a[j]>=c[j]){
                    sum[j]=a[j];
                    wei[1]+=1;
                    sum2[j]=c[j];
                }else{
                    sum[j]=c[j];
                    wei[3]+=1;
                    sum2[j]=a[j];
                }
            }else if(a[j]>=b[j]){
                if(a[j]>=c[j]){
                    sum[j]=a[j];
                    wei[1]+=1;
                    if(b[j]>=c[j]){
                        sum2[j]=b[j];
                    }
                    else{
                        sum2[j]=c[j];
                    }
                }else{
                    sum[j]=c[j];
                    wei[3]+=1;
                    sum2[j]=a[j];
                }
            }else{
                if(b[j]>=c[j]){
                    sum[j]=b[j];
                    wei[2]+=1;
                    if(c[j]>=a[j]){
                        sum2[j]=c[j];
                    }
                    else{
                        sum2[j]=a[j];
                    }
                }else{
                    sum[j]=c[j];
                    wei[3]+=1;
                    sum2[j]=b[j];
                }
            }w=j;
        }
        if(wei[1]<=s/2&&wei[2]<=s/2&&wei[3]<=s/2){
            for(int j=1;j<=w;j++){
                z+=sum[j];
            }
            cout<<z;
        }else if(wei[1]>s/2||wei[2]>s/2||wei[3]>s/2){
            if(sum[1]+sum2[2]>=sum[2]+sum2[1]){
                cout<<sum[1]+sum2[2];
            }else{
                cout<<sum[2]+sum2[1];
            }
        }
        z=0;
    }
    return 0;
}

