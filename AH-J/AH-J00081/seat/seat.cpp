#include<bits/stdc++.h>
using namespace std;
int m,n,s[101]={0},a[101]={0},c,r,temp=0,ans=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    if(n==1&&m==1){
        c=1;
        r=1;
    }
    cout<<c<<' '<<r;

    return 0;
}
