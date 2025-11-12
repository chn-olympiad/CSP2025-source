#include<bits/stdc++.h>
using namespace std;
int n;
int a[50011];
int dg(int i,long long o,int xb){
    long long sl=0;
    for(int q=xb+1;q<=n;q++){
        if(i+o>a[q]){
            sl++;
        }
    }
    if(xb+1==n){
        return sl%998244353;
    }else{
        long long pp=0;
        for(int q=1;xb+q<n;q++){
            pp=(pp+dg(i,o+a[xb+q],xb+q))%998244353;
        }
        return (sl+pp)%998244353;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long sl=0;
    for(int i=1;i<n-1;i++){
        for(int o=i+1;o<n;o++){
            sl=(sl+dg(a[i],a[o],o))%998244353;
        }
    }
    cout<<sl;
    return 0;
}
