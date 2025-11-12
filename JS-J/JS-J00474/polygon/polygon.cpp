#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int n,a[N],cnt=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(n>=3){
        if(a[1]+a[2]>a[3]) cnt++;
    }
    if(n>=4){
        if(a[1]+a[2]>a[4]) cnt++;
        if(a[1]+a[3]>a[4]) cnt++;
        if(a[2]+a[3]>a[4]) cnt++;
        if(a[1]+a[2]+a[3]>a[4]) cnt++;
    }
    if(n>=5){
        if(a[1]+a[2]>a[5]) cnt++;
        if(a[1]+a[3]>a[5]) cnt++;
        if(a[1]+a[4]>a[5]) cnt++;
        if(a[2]+a[3]>a[5]) cnt++;
        if(a[2]+a[4]>a[5]) cnt++;
        if(a[3]+a[4]>a[5]) cnt++;
        if(a[1]+a[2]+a[3]>a[5]) cnt++;
        if(a[1]+a[2]+a[4]>a[5]) cnt++;
        if(a[1]+a[3]+a[4]>a[5]) cnt++;
        if(a[2]+a[3]+a[4]>a[5]) cnt++;
        if(a[1]+a[2]+a[3]+a[4]>a[5]) cnt++;
    }
    if(n>=6){
        if(a[1]+a[2]>a[6]) cnt++;
        if(a[1]+a[3]>a[6]) cnt++;
        if(a[1]+a[4]>a[6]) cnt++;
        if(a[1]+a[5]>a[6]) cnt++;
        if(a[2]+a[3]>a[6]) cnt++;
        if(a[2]+a[4]>a[6]) cnt++;
        if(a[2]+a[5]>a[6]) cnt++;
        if(a[3]+a[4]>a[6]) cnt++;
        if(a[3]+a[5]>a[6]) cnt++;
        if(a[4]+a[5]>a[6]) cnt++;
        if(a[1]+a[2]+a[3]>a[6]) cnt++;
        if(a[1]+a[2]+a[4]>a[6]) cnt++;
        if(a[1]+a[2]+a[5]>a[6]) cnt++;
        if(a[1]+a[3]+a[4]>a[6]) cnt++;
        if(a[1]+a[3]+a[5]>a[6]) cnt++;
        if(a[1]+a[4]+a[5]>a[6]) cnt++;
        if(a[2]+a[3]+a[4]>a[6]) cnt++;
        if(a[2]+a[3]+a[5]>a[6]) cnt++;
        if(a[2]+a[4]+a[5]>a[6]) cnt++;
        if(a[3]+a[4]+a[5]>a[6]) cnt++;
        if(a[1]+a[2]+a[3]+a[4]>a[6]) cnt++;
        if(a[1]+a[2]+a[3]+a[5]>a[6]) cnt++;
        if(a[1]+a[2]+a[4]+a[5]>a[6]) cnt++;
        if(a[1]+a[3]+a[4]+a[5]>a[6]) cnt++;
        if(a[2]+a[3]+a[4]+a[5]>a[6]) cnt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]>a[6]) cnt++;
    }
    cout<<cnt;
    return 0;
}
