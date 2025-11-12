#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+7;
int n;
int a[N],sum[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n<3){
        cout<<0<<endl;
        return 0;
    }
    if(n==3){
        if(a[3]*2>=(a[1]+a[2]+a[3])){
            cout<<0<<endl;
            return 0;
        }
        else{
            cout<<1<<endl;
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if((a[i]-sum[i]+sum[k])/2>a[k])ans++;
            }
        }
    }
    cout<<ans+1<<"\n";
    return 0;
}
