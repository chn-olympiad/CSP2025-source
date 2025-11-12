#include <bits/stdc++>
using namespace std;
int main(){
    int n,m,s=1,n0,m0
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
        if(a[i]>a[0]){
            s++;
        }
    }
    n0=(s-1)%n+1;
    m0=(s-1)/n+1;
    if(m%2==0){
        n0=n-n0+1;
    }
    cout<<m0<<" "<<n0;
    return 0;
}
