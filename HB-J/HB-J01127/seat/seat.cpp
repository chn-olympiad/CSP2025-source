#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int c=a[1];
    sort(a+1,a+1+n*m);
    int mc=1;
    while(a[n*m-mc+1]!=c){
        mc++;
    }
    int l=mc/n;
    int r=mc%n;
    if(r>0)l++;
    else r=n;
    if(l%2==1){
        cout<<l<<" "<<r;
    }else{

        cout<<l<<" "<<n-r+1;
    }
    return 0;
}
