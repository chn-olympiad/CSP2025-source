#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a[5010],b,l[5010],x=1;
    long long z=0;
    cin>>b;
    if(b==3){
        cout<<1;
        return 0;
    }
    else if(b<=3){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=b;i++) cin>>a[i];
    for(int i=1;i<=b-3;i++){
        for(int j=i+2;j<=b;j++){
            l[1]=a[i];
            l[2]=a[i+1];
            l[3]=a[j];
            sort(l+1,l+3);
            if(l[3]*2<l[1]+l[2]+l[3]) z++;
            l[1]=a[i];
            l[2]=a[j-1];
            l[3]=a[j];
            sort(l+1,l+3);
            if(l[3]*2<l[1]+l[2]+l[3]) z++;
        }
    }
    sort(a+1,a+4);
    if(b==4) cout<<(z+(a[1]+a[2]+a[3]+a[4]>a[4]*2))%9982244353;
    else{
        cout<<(z*3)%998244353;
    }
    return 0;
}
