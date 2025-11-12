#include<bits/stdc++.h>
using namespace std;
int a[120];
int main(){
  freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    cnt=a[1];
    sort(a+1,a+1+n*m);
    int h=1,l=1;
    for(int i=n*m;i>=1;i--){
        if(a[i]==cnt){
            cout<<l<<" "<<h;
            return 0;
        }
       if(l%2==0 && h!=1){
            h--;
       }else if(h!=n && l%2!=0){
           h++;
       }else if(l%2==0&&h==1 || l%2!=0&&h==n){
            l++;
       }

    }
    return 0;
}
