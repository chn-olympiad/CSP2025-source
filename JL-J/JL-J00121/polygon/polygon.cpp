#include<bits/stdc++.h>
using namespace std;
const long long rp=1e9;
const int fumu=2;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    long long ans,a[5010]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        sort(a+1,a+n+1,cmp);
        long long num=a[1]+a[2]+a[3];
        if(num>a[1]*2){
            cout<<1;
        }
        return 0;
    }
    if(n==4){
        int ans=0;
        sort(a+1,a+n+1,cmp);
        if(a[1]+a[2]+a[3]>a[1]*2) ans++;
        if(a[1]+a[2]+a[4]>a[1]*2) ans++;
        if(a[1]+a[3]+a[4]>a[1]*2) ans++;
        if(a[2]+a[3]+a[4]>a[2]*2) ans++;
        if(a[1]+a[2]+a[3]+a[4]>a[1]*2) ans++;
        cout<<ans;
        return 0;
    }
    if(n==5){
        int ans=0;
        sort(a+1,a+n+1,cmp);
        if(a[1]+a[2]+a[3]>a[1]*2) ans++;
        if(a[1]+a[2]+a[4]>a[1]*2) ans++;
        if(a[1]+a[2]+a[5]>a[1]*2) ans++;
        if(a[1]+a[3]+a[4]>a[1]*2) ans++;
        if(a[1]+a[3]+a[5]>a[1]*2) ans++;
        if(a[1]+a[4]+a[5]>a[1]*2) ans++;
        if(a[2]+a[3]+a[4]>a[2]*2) ans++;
        if(a[2]+a[3]+a[5]>a[2]*2) ans++;
        if(a[2]+a[4]+a[5]>a[2]*2) ans++;
        if(a[3]+a[4]+a[5]>a[3]*2) ans++;
        if(a[1]+a[2]+a[3]+a[4]>a[1]*2) ans++;
        if(a[1]+a[2]+a[3]+a[5]>a[1]*2) ans++;
        if(a[1]+a[2]+a[4]+a[5]>a[1]*2) ans++;
        if(a[1]+a[3]+a[4]+a[5]>a[1]*2) ans++;
        if(a[2]+a[3]+a[4]+a[5]>a[2]*2) ans++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]>a[1]*2) ans++;
        cout<<ans;
        return 0;
    }
    if(n==6){
        int ans=0;
        sort(a+1,a+n+1,cmp);
        if(a[1]+a[2]+a[3]>a[1]*2) ans++;
        if(a[1]+a[2]+a[4]>a[1]*2) ans++;
        if(a[1]+a[2]+a[5]>a[1]*2) ans++;
        if(a[1]+a[2]+a[6]>a[1]*2) ans++;
        if(a[1]+a[3]+a[4]>a[1]*2) ans++;
        if(a[1]+a[3]+a[5]>a[1]*2) ans++;
        if(a[1]+a[3]+a[6]>a[1]*2) ans++;
        if(a[1]+a[4]+a[5]>a[1]*2) ans++;
        if(a[1]+a[4]+a[6]>a[1]*2) ans++;
        if(a[1]+a[5]+a[6]>a[1]*2) ans++;
        if(a[2]+a[3]+a[4]>a[2]*2) ans++;
        if(a[2]+a[3]+a[5]>a[2]*2) ans++;
        if(a[2]+a[3]+a[6]>a[2]*2) ans++;
        if(a[2]+a[4]+a[5]>a[2]*2) ans++;
        if(a[2]+a[4]+a[6]>a[2]*2) ans++;
        if(a[2]+a[5]+a[6]>a[2]*2) ans++;
        if(a[3]+a[4]+a[5]>a[3]*2) ans++;
        if(a[3]+a[4]+a[6]>a[3]*2) ans++;
        if(a[3]+a[5]+a[6]>a[3]*2) ans++;
        if(a[4]+a[5]+a[6]>a[4]*2) ans++;
        if(a[1]+a[2]+a[3]+a[4]>a[1]*2) ans++;
        if(a[1]+a[2]+a[3]+a[5]>a[1]*2) ans++;
        if(a[1]+a[2]+a[3]+a[6]>a[1]*2) ans++;
        if(a[1]+a[2]+a[4]+a[5]>a[1]*2) ans++;
        if(a[1]+a[2]+a[4]+a[6]>a[1]*2) ans++;
        if(a[1]+a[2]+a[5]+a[6]>a[1]*2) ans++;
        if(a[1]+a[3]+a[4]+a[5]>a[1]*2) ans++;
        if(a[1]+a[3]+a[4]+a[6]>a[1]*2) ans++;
        if(a[1]+a[3]+a[5]+a[6]>a[1]*2) ans++;
        if(a[1]+a[4]+a[5]+a[6]>a[1]*2) ans++;
        if(a[2]+a[3]+a[4]+a[5]>a[2]*2) ans++;
        if(a[2]+a[3]+a[4]+a[6]>a[2]*2) ans++;
        if(a[2]+a[3]+a[5]+a[6]>a[2]*2) ans++;
        if(a[2]+a[4]+a[5]+a[6]>a[2]*2) ans++;
        if(a[3]+a[4]+a[5]+a[6]>a[3]*2) ans++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]>a[1]*2) ans++;
        if(a[1]+a[2]+a[3]+a[4]+a[6]>a[1]*2) ans++;
        if(a[1]+a[2]+a[3]+a[5]+a[6]>a[1]*2) ans++;
        if(a[1]+a[2]+a[4]+a[5]+a[6]>a[1]*2) ans++;
        if(a[1]+a[3]+a[4]+a[5]+a[6]>a[1]*2) ans++;
        if(a[2]+a[3]+a[4]+a[5]+a[6]>a[2]*2) ans++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>a[1]*2) ans++;
        cout<<ans;
        return 0;
    }
    if(n==7){
        int ans=0;
        sort(a+1,a+n+1,cmp);
        if(a[1]+a[2]+a[3]>a[1]*2) ans++;
        if(a[1]+a[2]+a[4]>a[1]*2) ans++;
        if(a[1]+a[2]+a[5]>a[1]*2) ans++;
        if(a[1]+a[2]+a[6]>a[1]*2) ans++;
        if(a[1]+a[2]+a[7]>a[1]*2) ans++;
        if(a[1]+a[3]+a[4]>a[1]*2) ans++;
        if(a[1]+a[3]+a[5]>a[1]*2) ans++;
        if(a[1]+a[3]+a[6]>a[1]*2) ans++;
        if(a[1]+a[3]+a[7]>a[1]*2) ans++;
        if(a[1]+a[4]+a[5]>a[1]*2) ans++;
        if(a[1]+a[4]+a[6]>a[1]*2) ans++;
        if(a[1]+a[4]+a[7]>a[1]*2) ans++;
        if(a[1]+a[5]+a[6]>a[1]*2) ans++;
        if(a[1]+a[5]+a[7]>a[1]*2) ans++;
        if(a[1]+a[6]+a[7]>a[1]*2) ans++;
        if(a[2]+a[3]+a[4]>a[2]*2) ans++;
        if(a[2]+a[3]+a[5]>a[2]*2) ans++;
        if(a[2]+a[3]+a[6]>a[2]*2) ans++;
        if(a[2]+a[3]+a[7]>a[2]*2) ans++;
        if(a[2]+a[4]+a[5]>a[2]*2) ans++;
        if(a[2]+a[4]+a[6]>a[2]*2) ans++;
        if(a[2]+a[4]+a[7]>a[2]*2) ans++;
        if(a[2]+a[5]+a[6]>a[2]*2) ans++;
        if(a[2]+a[5]+a[7]>a[2]*2) ans++;
        if(a[2]+a[6]+a[7]>a[2]*2) ans++;
        if(a[3]+a[4]+a[5]>a[3]*2) ans++;
        if(a[3]+a[4]+a[6]>a[3]*2) ans++;
        if(a[3]+a[4]+a[7]>a[3]*2) ans++;
        if(a[3]+a[5]+a[6]>a[3]*2) ans++;
        if(a[3]+a[5]+a[7]>a[3]*2) ans++;
        if(a[3]+a[6]+a[7]>a[3]*2) ans++;
        if(a[4]+a[5]+a[6]>a[4]*2) ans++;
        if(a[4]+a[5]+a[7]>a[4]*2) ans++;
        if(a[4]+a[6]+a[7]>a[4]*2) ans++;
        if(a[5]+a[6]+a[7]>a[5]*2) ans++;
        if(a[1]+a[2]+a[3]+a[4]>a[1]*2) ans++;
        if(a[1]+a[2]+a[3]+a[5]>a[1]*2) ans++;
        if(a[1]+a[2]+a[3]+a[6]>a[1]*2) ans++;
        if(a[1]+a[2]+a[3]+a[7]>a[1]*2) ans++;
        if(a[1]+a[2]+a[4]+a[5]>a[1]*2) ans++;
        if(a[1]+a[2]+a[4]+a[6]>a[1]*2) ans++;
        if(a[1]+a[2]+a[4]+a[7]>a[1]*2) ans++;
        if(a[1]+a[2]+a[5]+a[6]>a[1]*2) ans++;
        if(a[1]+a[2]+a[5]+a[7]>a[1]*2) ans++;
        if(a[1]+a[2]+a[6]+a[7]>a[1]*2) ans++;
        if(a[1]+a[3]+a[4]+a[5]>a[1]*2) ans++;
        if(a[1]+a[3]+a[4]+a[6]>a[1]*2) ans++;
        if(a[1]+a[3]+a[4]+a[7]>a[1]*2) ans++;
        if(a[1]+a[3]+a[5]+a[6]>a[1]*2) ans++;
        if(a[1]+a[3]+a[5]+a[7]>a[1]*2) ans++;
        if(a[1]+a[3]+a[6]+a[7]>a[1]*2) ans++;
        if(a[1]+a[4]+a[5]+a[6]>a[1]*2) ans++;
        if(a[1]+a[4]+a[5]+a[7]>a[1]*2) ans++;
        if(a[1]+a[4]+a[6]+a[7]>a[1]*2) ans++;
        if(a[1]+a[5]+a[6]+a[7]>a[1]*2) ans++;
        if(a[2]+a[3]+a[4]+a[5]>a[2]*2) ans++;
        if(a[2]+a[3]+a[4]+a[6]>a[2]*2) ans++;
        if(a[2]+a[3]+a[4]+a[7]>a[2]*2) ans++;
        if(a[2]+a[3]+a[5]+a[6]>a[2]*2) ans++;
        if(a[2]+a[3]+a[5]+a[7]>a[2]*2) ans++;
        if(a[2]+a[3]+a[6]+a[7]>a[2]*2) ans++;
        if(a[2]+a[4]+a[5]+a[6]>a[2]*2) ans++;
        if(a[2]+a[4]+a[5]+a[7]>a[2]*2) ans++;
        if(a[2]+a[4]+a[6]+a[7]>a[2]*2) ans++;
        if(a[2]+a[5]+a[6]+a[7]>a[2]*2) ans++;
        if(a[3]+a[4]+a[5]+a[6]>a[3]*2) ans++;
        if(a[3]+a[4]+a[5]+a[7]>a[3]*2) ans++;
        if(a[3]+a[4]+a[6]+a[7]>a[3]*2) ans++;
        if(a[3]+a[5]+a[6]+a[7]>a[3]*2) ans++;
        if(a[4]+a[5]+a[6]+a[7]>a[4]*2) ans++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]>a[1]*2) ans++;
        if(a[1]+a[2]+a[3]+a[4]+a[6]>a[1]*2) ans++;
        if(a[1]+a[2]+a[3]+a[4]+a[7]>a[1]*2) ans++;
        if(a[1]+a[2]+a[3]+a[5]+a[6]>a[1]*2) ans++;
        if(a[1]+a[2]+a[3]+a[5]+a[7]>a[1]*2) ans++;
        if(a[1]+a[2]+a[3]+a[6]+a[7]>a[1]*2) ans++;
        if(a[1]+a[2]+a[4]+a[5]+a[6]>a[1]*2) ans++;
        if(a[1]+a[2]+a[4]+a[5]+a[7]>a[1]*2) ans++;
        if(a[1]+a[2]+a[4]+a[6]+a[7]>a[1]*2) ans++;
        if(a[1]+a[3]+a[4]+a[5]+a[6]>a[1]*2) ans++;
        if(a[1]+a[3]+a[4]+a[5]+a[7]>a[1]*2) ans++;
        if(a[1]+a[3]+a[4]+a[6]+a[7]>a[1]*2) ans++;
        if(a[1]+a[3]+a[5]+a[6]+a[7]>a[1]*2) ans++;
        if(a[1]+a[4]+a[5]+a[6]+a[7]>a[1]*2) ans++;
        if(a[2]+a[3]+a[4]+a[5]+a[6]>a[2]*2) ans++;
        if(a[2]+a[3]+a[4]+a[5]+a[7]>a[2]*2) ans++;
        if(a[2]+a[3]+a[4]+a[6]+a[7]>a[2]*2) ans++;
        if(a[2]+a[3]+a[5]+a[6]+a[7]>a[2]*2) ans++;
        if(a[2]+a[4]+a[5]+a[6]+a[7]>a[2]*2) ans++;
        if(a[3]+a[4]+a[5]+a[6]+a[7]>a[3]*2) ans++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>a[1]*2) ans++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[7]>a[1]*2) ans++;
        if(a[1]+a[2]+a[3]+a[4]+a[6]+a[7]>a[1]*2) ans++;
        if(a[1]+a[2]+a[3]+a[5]+a[6]+a[7]>a[1]*2) ans++;
        if(a[1]+a[2]+a[4]+a[5]+a[6]+a[7]>a[1]*2) ans++;
        if(a[1]+a[3]+a[4]+a[5]+a[6]+a[7]>a[1]*2) ans++;
        if(a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>a[2]*2) ans++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>a[1]*2) ans++;
        cout<<ans;
        return 0;
    }
    return 0;
}
