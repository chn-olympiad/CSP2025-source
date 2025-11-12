#include<bits/stdc++.h>
using namespace std;
long long a[5010],cnt=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int t=3;t<=n;t++){
        for(int i=1;i<=n-t+1;i++){
            long long sum=a[i];
            for(int j=i+1;j<=n-t+2;j++){
                    sum+=a[j];
                    sum%=998244353;
                for(int k=j+1;k<=n-t+3;k++){
                    for(int l=1;l<=t-2;l++){
                        sum+=a[k+l]%998244353;
                        sum%=998244353;
                    }
                    if(sum<=a[k+t-2]*2){
                        k++;
                        sum=a[i]+a[j];
                    }
                    else{
                        cnt++;
                        sum=a[i]+a[j];
                    }

                }
                sum=a[i];

            }

        }
    }
    cout<<cnt%998244353;
    return 0;
}
