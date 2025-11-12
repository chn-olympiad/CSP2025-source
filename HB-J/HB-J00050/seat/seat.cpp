#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1800];
int main(){
 freopen("seat.in","r",stdin);
 freopen("seat.out","w",stdout);
    cin>>n>>m;
    int ge=1;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1]){
            ge++;
        }
    }
 // cout<<ge;
 if(ge==1){
    cout<<"1"<<" "<<"1";
    return 0;
 }
 if(ge%n==0){
    int lie=ge/n;
    if(lie%2==0){
        cout<<lie<<" "<<"1";
    }else{
    cout<<lie<<" "<<m;
    }
 }else{
 int lie=ge/n+1;
 int pai=0;
 if(lie%2==0){
    pai=m-(ge-(lie-1)*n)+1;
 }else{
 pai=ge-(lie-1)*n;
 }
 cout<<lie<<" "<<pai;
 }
return 0;
}/*     3 3
 94 95 96 97 98 99 100 93 92  */
