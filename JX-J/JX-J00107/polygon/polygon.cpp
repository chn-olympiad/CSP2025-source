#include<bits/stdc++.h>
using namespace std;
int a[1005],b[1005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,cnt=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        b[i]=b[i-1]+a[i];
    }
    if(n=3){
        if(b[2]>a[2]*2)cout<<'1';
        else cout<<'0';
        return 0;
    }
    if(b[2]>a[2]*2)cnt++;
    for(int i=0;i<n-3;i++){
        for(int j=i+3;j<n;j++){
            if(b[j]-b[i]>a[j]*2)cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
