#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000001];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int cj=a[1];
    int o;
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==cj){
            o=n*m-i+1;
        }
    }
    int l=o/n;
    o=o%n;
    if(o==0){
        if(l%2==1){
            cout<<l<<' '<<n;
        }else{
            cout<<l<<' '<<1;
        }
    }else{
        l++;
        if(l%2==1){
            cout<<l<<' '<<o;
        }else{
            cout<<l<<' '<<n-o+1;
        }
    }
    return 0;
}
