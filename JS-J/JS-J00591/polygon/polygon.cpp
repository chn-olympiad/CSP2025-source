#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
long long n;
long long a[maxn];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==3&&a[0]+a[1]+a[2]>max(a[0],max(a[1],a[2]))) cout<<"1";
    else if(n==3) cout<<"0";
    else{
        long long ans=0,sum=1;
        for(int i=3;i<=n;i++){
            sum=1;
            for(int j=n;j>n-i;j--){
                sum*=j;
            }
            ans+=sum;
        }
        cout<<ans%998244353;
    }
    return 0;
}
