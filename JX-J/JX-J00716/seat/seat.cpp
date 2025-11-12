#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,a[10001];
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int k=a[0];
    for(int i=0;i<n*m;i++){
        for(int j=0;j<n*m-i;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=0;i<n*m;i++){
        if(a[i]==k){
            k=i;
        }
    }
    int s=1;
    int h=1,l=1;
    while(1){
        if(k==0){
            break;
        }
        if(s==1){
           if(h<n){
             h++;
             k--;
           }
           else {
                l++,s=0,k--;
           }
        }
        else{
            if(h>1){
                h--;
                k--;
            }
            else {
                l++,s=1,k--;
           }
        }
    }
    cout<<l<<" "<<h;
    return 0;
}
