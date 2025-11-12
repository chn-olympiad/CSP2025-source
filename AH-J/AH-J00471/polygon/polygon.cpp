#include<bits/stdc++.h>
using namespace std;
int n,a[5005],qz1[5005],qz2[5005],cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        qz1[i]=qz1[i-1]+a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    for(int i=1;i<=n;i++){
        qz2[i]=qz2[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+2;j<=n;j++){
            if(a[i]*2<qz1[n]-qz1[i-1]-qz2[n-j]){
                cnt++;
                cnt%=998244353;
            }
        }
    }
    cout<<cnt;
    return 0;
}
