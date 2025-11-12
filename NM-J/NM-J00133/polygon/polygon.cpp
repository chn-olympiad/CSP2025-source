#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,l[5001];
    long long gs=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>l[i];
    }
    sort(l,l+n);
    for(int i=0;i<=n-3;i++){
        if(l[0+i]+l[1+i]>l[2+i]&&l[0+i]+l[2+i]>l[1+i]&&l[2+i]+l[1+i]>l[0+i]) gs++;//sanjiaoxing
    }
    for(int i=0;i<=n-4;i++){
        if(l[0+i]+l[1+i]+l[3+i]>l[2+i]&&l[0+i]+l[2+i]+l[3+i]>l[1+i]&&l[2+i]+l[1+i]+l[3+i]>l[0+i]&&l[3+i]<l[0+i]+l[1+i]+l[2+i]) gs++;//sibianxing
    }
    for(int i=0;i<=n-5;i++){
        if(l[0+i]+l[1+i]+l[3+i]+l[4+i]>l[2+i]&&l[0+i]+l[2+i]+l[3+i]+l[4+i]>l[1+i]&&l[2+i]+l[1+i]+l[3+i]+l[4+i]>l[0+i]&&l[3+i]<l[0+i]+l[4+i]+l[1+i]+l[2+i]&&l[4+i]<+l[5+i]) gs++;//sanjiaoxing
    }
    cout<<gs%998244353;
    return 0;
}
