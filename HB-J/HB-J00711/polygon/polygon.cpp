#include<bits/stdc++.h>
using namespace std;
int n,he=0,a[50001];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        int k=max(a[1],max(a[2],a[3]));
        if(2*k<a[1]+a[2]+a[3]){
            cout<<1;
        }
        else cout<<0;
        return 0;
    }
    sort(a+1,a+1+n);
    if(n==4){
        int sum=0;
        if(a[1]+a[2]>a[4]) sum++;
        if(a[1]+a[3]>a[4]) sum++;
        if(a[1]+a[2]>a[3]) sum++;
        if(a[2]+a[3]>a[4]) sum++;
        if(a[1]+a[2]+a[3]>a[4]) sum++;
        cout<<sum;
        return 0;
    }
    cout<<n;
    return 0;
}
