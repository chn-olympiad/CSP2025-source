#include <bits/stdc++.h>
using namespace std;
int n;
int s=0;
int a[5000+10];
int main(){
    freopen("polygon.in","w",stdin);
    freopen("polygon.out","r",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]+a[i+1]>a[i+2] and a[i+2]+a[i+1]>a[i] and a[i+1]+a[i+2]>a[i+1]){
            s++;
            break;
        }
        a[i]=a[i]++;
        if(n>=3 and a[i]>2*max(n,a[i])){
            s++;
        }
    }
    cout<<s;
    return 0;
}
