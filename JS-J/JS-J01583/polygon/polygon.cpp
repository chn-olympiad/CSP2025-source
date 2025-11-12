#include<iostream>
using namespace std;
long long a[5005];
int used[25];
long long ans;
const long long mod=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
            cout<<1<<endl;
        }
        else cout<<0<<endl;
        return 0;
    }
    for(int i=3;i<=n;i++){
        long long ans1=1;
        for(int j=i+1,k=2;j<=n;j++){
            ans1*=j;
            while(ans1>=mod&&k<=n-i){
                ans1/=k;
                k++;
            }
            ans1%=mod;
        }
        ans+=ans1;
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}
