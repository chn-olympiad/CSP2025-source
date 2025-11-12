#include<bits/stdc++.h>
using namespace std;
int a[1000006],k,n,m,p;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;k=n*m;
    for(int i=1;i<=k;i++){
        cin>>a[i];
        if(a[i]>=a[1]) p++;
    }int h=p/n,l=p%n;
    if(l==0){
        l=n;
    }if(h%2==1){
        l=m-l+1;
    }cout<<h+1<<" "<<l;
    return 0;
}
