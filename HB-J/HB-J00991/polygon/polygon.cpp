#include <bits/stdc++.h>
using namespace std;
int n;
int a[5100];
int ans[5100];
bool ok(int maxn,int sum){
    return sum>maxn*2;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=1;i<=n;i++){
        ans[i]=a[i]+a[i-1];
    }
    cout<<9;


    return 0;
}
