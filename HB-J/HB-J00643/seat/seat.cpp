#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,h,l;//m hang n lie
    cin>>m>>n;
    int a[m*n],b[101]={},c,d=0;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    c=a[0];
    for(int i=0;i<n*m;i++){
        b[a[i]]++;
    }
    for(int i=100;i>=0;i--){
        if(b[i]){
            a[d]=i;
            d++;
        }
    }
    for(int i=0;i<n*m;i++){
        if(a[i]==c){
            h=i/m;
            cout<<h+1<<" ";
            l=i-h*m;
            if(h%2==0){
                cout<<l+1;
            }
            else{
                cout<<m-l;
            }
        }
    }
    return 0;
}
