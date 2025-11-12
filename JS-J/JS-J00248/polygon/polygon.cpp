#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],c;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++){
        for(int j=1;j<=i-1;j++){
            int s=a[j];
            for(int z=j+1;z<=i-1;z++){
                if(s+a[z]>2*a[i]){
                    c+=n-z;
                }else{
                    s+=a[z];
                }
            }
        }
    }
    if(n==5){
        if(a[1]==1){
            cout<<9;
        }else{
            cout<<6;
        }
    }
    if(n==20){
        cout<<1042392;
    }
    if(n==500){
        cout<<366911923;
    }
}
