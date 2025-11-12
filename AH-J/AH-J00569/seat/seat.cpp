#include<bits/stdc++.h>
using namespace std;
long long i,n,m,a[9999990],b[500][500],cnt,hang=1,nie=1,f;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(i=0;i<n*m;i++){
        cin>>a[i];
    }
    f=a[0];
    sort(a,a+n);
    for(i=n*m-1;i>=0;i++){
        cnt++;
        if(a[i]==f){
        break;
        }
    }
    while(cnt/n>0){
         cnt=cnt-n;
         nie++;
    }
    if(nie%2==0){
       if(cnt!=0){
          hang=n+1-cnt;
       }else{
          hang=1;
          nie--;
       }
    }else{
       if(cnt!=0){
          hang=cnt;
       }else{
          hang=n;
          nie--;
       }
    }
    cout<<nie<<" "<<hang;
    return 0;
}
