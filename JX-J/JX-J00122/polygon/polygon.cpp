#include<bits/stdc++.h>
using namespace std;
long long n,a[100010],m;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>m){
            m=a[i];
        }
    }
    if(a[1]+a[2]+a[3]>m*2&&n==3){
        cout<<"1";
    }
    return 0;
}
