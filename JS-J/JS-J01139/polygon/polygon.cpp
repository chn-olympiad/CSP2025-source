#include <bits/stdc++.h>
using namespace std;
bool f;
long long n,k,cnt=0,t,a[10000];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)f=0;
        k+=a[i];t=max(a[i],t);
    }
    if(n==3){
        if(k>2*t)cnt=1;
    }
    else{
        for(int i=3;i<=n;i++){
            long long x=1;
            for(int j=1;j<=i;j++){
                x=x*(n-j+1);
                x/=j;
            }
            cnt+=x;
        }
    }
    cout<<cnt;
    return 0;
}
