#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m];
    int f;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
        if(i==0){
            f=a[i];
        }

    }
    sort(a,a+n*m,cmp);
    int t;
    for(int i=0;i<n*m;i++){
        if(f==a[i]){
            t=i+1;
            break;
        }
    }
    int k=ceil(t*1.0/n);
    cout<<k<<" ";
    int z=t%n;
    if(k%2)
        if(z!=0) cout<<z;
        else cout<<n;
    else
        if(z!=0) cout<<n-z+1;
        else cout<<1;
    return 0;
}
