#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans;
bool flag=1;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        long long max1=0,min1;
        for(int i=1;i<=3;i++){
            if(a[i]>max1)max1=a[i];
        }
        if(a[1]==max1){
            if(a[2]+a[3]>max1){
                    cout<<1;
                    return 0;
            }
        }
        else if(a[2]==max1){
            if(a[1]+a[3]>max1){
                    cout<<1;
                    return 0;
            }
        }
        else if(a[3]==max1){
            if(a[2]+a[1]>max1){
                    cout<<1;
                    return 0;
            }
        }
        cout<<0;
        return 0;
        }
    else{
        sort(a+1,a+1+n);
        for(int i=n;i>=1;i--){
            for(int j=3;j<=i;j++){
                long long max2=0,min2=0;
                for(int k=1;k<=j;k++){
                    if(max2<a[k])max2=a[k];
                    min2=min2+a[k];
                }
                if(min2>2*max2)ans++;
            }
        }
        if(ans>998)ans=ans%998;
        else if(ans>353)ans=ans%353;
        else if(ans>244)ans=ans%244;
        cout<<ans;
    }
    return 0;
}
