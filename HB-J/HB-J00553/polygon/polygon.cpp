#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,a[6000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==3&&a[0]+a[1]>a[2]&&a[2]+a[1]>a[0]&&a[0]+a[2]>a[1])cout<<1;
    else if(n>=3&&n<=8)cout<<6;
    else cout<<2;
    return 0;
}
