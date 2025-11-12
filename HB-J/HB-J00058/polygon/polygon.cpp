#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            int ma7xx=-99999;
            int ans=0;
            for(int j=i;j<=i+k;j++){
                if(a[j]>ma7xx){
                    ma7xx=a[j];
                }
                ans+=a[j];
            }
            if(ans>ma7xx*2){
                sum++;
            }
        }
    }
    cout<<sum%998244353-3;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
