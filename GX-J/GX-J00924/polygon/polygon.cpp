#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a[100005],n,max,g,s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<=n;i++){
        max=a[i-1];
        s=a[i+1]+a[i-1]+a[i+n+1]+a[i-n-1]+a[i+n-1]+a[i-n+1]+a[i]+a[n]+a[n-1]+a[n+1]+a[n+i];
        if(s>max*2){
            g=g+1;
        }
    }
    cout<<g+3;
    return 0;
}
//.
