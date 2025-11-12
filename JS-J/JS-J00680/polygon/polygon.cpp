#include<bits/stdc++.h>
using namespace std;
int n,a[5050],sum[5050];
long long ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n<=3){
        if(n<3){
            cout<<0<<endl;
            return 0;
        }
        else{
            if(n==3){
                int h=a[0]+a[1]+a[2],mx=max(a[0],max(a[1],a[2]));
                if(h>2*mx){
                    cout<<1<<endl;
                    return 0;
                }
                else{
                    cout<<0<<endl;
                    return 0;
                }
            }
        }
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(i==0){
            sum[i]=a[i];
        }
        else{
            sum[i]=sum[i-1]+a[i];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+3;j<n;j++){
            int c=sum[j]-sum[i];
            if(c>2*a[j]){
                ans++;
                ans%=998244353;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
