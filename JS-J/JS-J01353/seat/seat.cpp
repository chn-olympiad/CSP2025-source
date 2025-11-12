#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long n,m;
    cin>>n>>m;
    long long f,ans=0,ans_n,ans_m;
    cin>>f;
    for(long long i=1;i<n*m;i++){
        long long x;
        cin>>x;
        if(x>f)ans++;
    }
    ans++;
    ans_m=(ans+n-1)/n;
    if(ans_m%2==1){
        ans_n=ans%n;
    }else{
        ans_n=n-ans%n+1;
    }
    if(ans_n==0){
        ans_n=n;
    }
    cout<<ans_m<<' '<<ans_n;
    return 0;
}
