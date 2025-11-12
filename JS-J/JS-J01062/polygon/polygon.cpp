#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n;
    cin>>n;
    int a[5010],maxn=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(maxn==1){
        cout<<(n*(n-1)*(n-2)/6)%mod;
        return 0;
    }
    if(n==1||n==2){
        cout<<0;
    }else if(n==3){
        sort(a+1,a+n+1);
        if(a[1]+a[2]>a[3]){
            cout<<1;
        }else{
            cout<<0;
        }
    }else if(n==4){
        sort(a+1,a+n+1);
        int cnt=0;
        if(a[1]+a[2]>a[3])cnt++;
        if(a[1]+a[2]>a[4])cnt++;
        if(a[1]+a[3]>a[4])cnt++;
        if(a[2]+a[3]>a[4])cnt++;
        if(a[1]+a[2]+a[3]>a[4])cnt++;
        cout<<cnt;
    }else if(n==5){
        sort(a+1,a+n+1);
        int cnt=0;
        if(a[1]+a[2]>a[3])cnt++;
        if(a[1]+a[2]>a[4])cnt++;
        if(a[1]+a[2]>a[5])cnt++;
        if(a[1]+a[3]>a[4])cnt++;
        if(a[1]+a[3]>a[5])cnt++;
        if(a[1]+a[4]>a[5])cnt++;
        if(a[2]+a[3]>a[4])cnt++;
        if(a[2]+a[3]>a[5])cnt++;
        if(a[2]+a[4]>a[5])cnt++;
        if(a[3]+a[4]>a[5])cnt++;
        if(a[1]+a[2]+a[3]>a[4])cnt++;
        if(a[1]+a[2]+a[3]>a[5])cnt++;
        if(a[1]+a[2]+a[4]>a[5])cnt++;
        if(a[1]+a[3]+a[4]>a[5])cnt++;
        if(a[2]+a[3]+a[4]>a[5])cnt++;
        if(a[1]+a[2]+a[3]+a[4]>a[5])cnt++;
        cout<<cnt;
    }else if(n==6){
        sort(a+1,a+n+1);
        int cnt=0;
        if(a[1]+a[2]>a[3])cnt++;
        if(a[1]+a[2]>a[4])cnt++;
        if(a[1]+a[2]>a[5])cnt++;
        if(a[1]+a[2]>a[6])cnt++;
        if(a[1]+a[3]>a[4])cnt++;
        if(a[1]+a[3]>a[5])cnt++;
        if(a[1]+a[3]>a[6])cnt++;
        if(a[1]+a[4]>a[5])cnt++;
        if(a[1]+a[4]>a[6])cnt++;
        if(a[1]+a[5]>a[6])cnt++;
        if(a[2]+a[3]>a[4])cnt++;
        if(a[2]+a[3]>a[5])cnt++;
        if(a[2]+a[3]>a[6])cnt++;
        if(a[2]+a[4]>a[5])cnt++;
        if(a[2]+a[4]>a[6])cnt++;
        if(a[2]+a[5]>a[6])cnt++;
        if(a[3]+a[4]>a[5])cnt++;
        if(a[3]+a[4]>a[6])cnt++;
        if(a[3]+a[5]>a[6])cnt++;
        if(a[4]+a[5]>a[6])cnt++;
        if(a[1]+a[2]+a[3]>a[4])cnt++;
        if(a[1]+a[2]+a[3]>a[5])cnt++;
        if(a[1]+a[2]+a[3]>a[6])cnt++;
        if(a[1]+a[2]+a[4]>a[5])cnt++;
        if(a[1]+a[2]+a[4]>a[6])cnt++;
        if(a[1]+a[2]+a[5]>a[6])cnt++;
        if(a[1]+a[3]+a[4]>a[5])cnt++;
        if(a[1]+a[3]+a[4]>a[6])cnt++;
        if(a[1]+a[3]+a[5]>a[6])cnt++;
        if(a[1]+a[4]+a[5]>a[6])cnt++;
        if(a[2]+a[3]+a[4]>a[5])cnt++;
        if(a[2]+a[3]+a[4]>a[6])cnt++;
        if(a[2]+a[3]+a[5]>a[6])cnt++;
        if(a[2]+a[4]+a[5]>a[6])cnt++;
        if(a[3]+a[4]+a[5]>a[6])cnt++;
        if(a[1]+a[2]+a[3]+a[4]>a[5])cnt++;
        if(a[1]+a[2]+a[3]+a[4]>a[6])cnt++;
        if(a[1]+a[2]+a[3]+a[5]>a[6])cnt++;
        if(a[1]+a[2]+a[4]+a[5]>a[6])cnt++;
        if(a[1]+a[3]+a[4]+a[5]>a[6])cnt++;
        if(a[2]+a[3]+a[4]+a[5]>a[6])cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]>a[6])cnt++;
        cout<<cnt;
    }
    return 0;
}
