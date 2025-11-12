#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum,ans,tns;
bool b[5005];
int main(){
//    freopen("polygon.in","r",stdin);
//    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        b[i]=0;
    }
    tns=sum;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(sum%2==0&&a[i]>=sum/2||sum%2==1&&a[i]>sum/2){
            b[i]=1;
            n--;
            tns-=a[i];
        }
    }
    if(tns%2==0) tns++;
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3&&a[3]<tns/2+1){
        cout<<1;
        return 0;
    }
    if(n==4){
        for(int i=1;i<=2;i++){
            for(int j=i+1;j<=3;j++){
                for(int k=j+1;k<=4;k++){
                    if(b[i]||b[j]||b[k]) continue;
                    else{
                        if(a[k]<(a[i]+a[j]+a[k])/2) ans++;
                    }
                }
            }
        }
        for(int i=n;i>0;i--){
            if(b[i]==0&&a[i]<sum/2){
                ans++;
                break;
            }
        }
    }
    if(n==5){
        for(int i=1;i<=3;i++){
            for(int j=i+1;j<=4;j++){
                for(int k=j+1;k<=5;k++){
                    if(b[i]||b[j]||b[k]) continue;
                    else{
                        if(a[k]<(a[i]+a[j]+a[k])/2) ans++;
                    }
                }
            }
        }
        for(int i=1;i<=2;i++){
            for(int j=i+1;j<=3;j++){
                for(int k=j+1;k<=4;k++){
                    for(int l=k+1;l<=5;l++){
                        if(b[i]||b[j]||b[k]||b[l]) continue;
                        else{
                            if(a[l]<(a[i]+a[j]+a[k]+a[l])/2) ans++;
                        }
                    }
                }
            }
        }
        for(int i=n;i>0;i--){
            if(b[i]==0&&a[i]<sum/2){
                ans++;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
