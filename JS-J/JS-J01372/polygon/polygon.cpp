#include<bits/stdc++.h>
using namespace std;
int n,b[5005];
int main(){
ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    sort(b,b+n);
   if(n<3){
    cout<<0;
    return 0;
   }if(n==3){
       if(b[0]+b[1]>b[2]){
        cout<<1;
       }else cout<<0;
       return 0;
   }else cout<<0;
    return 0;
}
