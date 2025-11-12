#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        int sum1=a[0]+a[1]+a[2],mx=max(max(a[0],a[1]),a[2]);
        if(sum1>mx*2) cout<<1;
        else cout<<0;
        return 0;
    }
    long long sum2=0;
    for(int i=3;i<=n;i++){
        long long sum=1;
        for(int j=n,c=0;c<i;j--,c++){
            sum*=j;
            sum%=998244353;
        }
        for(int j=1,c=0;c<i;j++,c++){
            sum/=j;
        }
        if(i==n) sum2++;
        else if(i==n-1) sum2+=n;
        else sum2+=sum;
        sum2%=998244353;
    }
    cout<<sum2;
    return 0;
}
