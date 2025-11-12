#include <bits/stdc++.h>
using namespace std;
int n,a[5005];
bool pf=1;
long long ccc(int n1,int i1){
    long long s=1;
    for(int j=1;j<=n1;j++){
        s*=j;
        if(j<=i1*(n1-i1)){
            s/=j;
        }
    }
    return s;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=1){
            pf=0;
        }
    }
    sort(a+1,a+n+1);
    if(n==3){
        if(a[1]+a[2]>a[3]){
            cout<<1;
        }else{
            cout<<0;
        }
    }else if(pf){
        long long z=0;
        for(int i=3;i<=n;i++){
            z+=ccc(n,i);
            z%=998244353;
        }
        cout<<z;
    }
    return 0;
}

