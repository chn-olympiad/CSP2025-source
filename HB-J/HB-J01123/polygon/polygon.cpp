#include<bits/stdc++.h>
using namespace std;
int n,a[5005],cnt;
int main(){
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    bool flag1=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n<3){
        cout<<"0";
        return 0;
    }
    if(n==3){
        if(a[1]+a[2]+a[3]>a[3]*2){
            cout<<1;
            return 0;
        }
        else if(a[1]+a[2]+a[3]<a[3]*2){
            cout<<0;
            return 0;
        }
    }
    else if(n==4){
        int cnt1=0;
        if(a[1]+a[2]+a[3]>a[3]*2) cnt1++;
        if(a[1]+a[2]+a[4]>a[4]*2) cnt1++;
        if(a[1]+a[3]+a[4]>a[4]*2) cnt1++;
        if(a[2]+a[3]+a[4]>a[4]*2) cnt1++;
        if(a[1]+a[2]+a[3]+a[4]>a[4]*2) cnt1++;
        cout<<cnt1;
        return 0;
    }
    else if(n==5){
        int cnt2=0;
        if(a[1]+a[2]+a[3]>a[3]*2) cnt2++;
        if(a[1]+a[2]+a[4]>a[4]*2) cnt2++;
        if(a[1]+a[2]+a[5]>a[5]*2) cnt2++;
        if(a[1]+a[3]+a[4]>a[4]*2) cnt2++;
        if(a[1]+a[3]+a[5]>a[5]*2) cnt2++;
        if(a[1]+a[4]+a[5]>a[5]*2) cnt2++;
        if(a[2]+a[3]+a[4]>a[4]*2) cnt2++;
        if(a[2]+a[3]+a[5]>a[5]*2) cnt2++;
        if(a[2]+a[4]+a[5]>a[5]*2) cnt2++;
        if(a[3]+a[4]+a[5]>a[5]*2) cnt2++;
        if(a[1]+a[2]+a[3]+a[4]>a[4]*2) cnt2++;
        if(a[1]+a[2]+a[3]+a[5]>a[5]*2) cnt2++;
        if(a[1]+a[2]+a[4]+a[5]>a[5]*2) cnt2++;
        if(a[1]+a[3]+a[4]+a[5]>a[5]*2) cnt2++;
        if(a[2]+a[3]+a[4]+a[5]>a[5]*2) cnt2++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]>a[5]*2) cnt2++;
        cout<<cnt2;
        return 0;
    }
    if(flag1==1){
        int cnt3=3;
        unsigned long long d=1,e=1;
        unsigned long long m=0;
        for(int i=1;i<=n-2;i++){
            for(int j=0;j<cnt3;j++){
                d*=(n-j);
            }
            for(int j=1;j<=cnt3;j++){
                e*=j;
            }
            m+=d/e;
            m=m%998244353;
            cnt3++;
            d=1;
            e=1;
        }
        cout<<m;
    }
    return 0;
}
