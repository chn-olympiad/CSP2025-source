#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;cin>>n;
    int a[n+5],maxn=-1;
    bool F=true;
    for(int i=1;i<=n;i++){
        cin>> a[i];
        if(a[i]!=1)F=false;
        maxn=max(maxn,a[i]);
    }
    if(n==3){
        if((a[1]+a[2]+a[3])>maxn){
            cout << 1;
        }
    }
    return 0;
}
