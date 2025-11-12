#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen('seat.in','r',stdin);
    freopen('seat.out','w',stdout);
    int n, m, r, a[105], k=0;
    cin>>n>>m;
    cin>>r;
    for(int i=0; i<=n*m-1; i++){
        cin>>a[i];
    }
    for(int i=1; i<=n*m-1; i++){
        for(int j=i; j<=n*m-1; j++){
            if(a[j]<a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
    if(r>=a[0]) k=0;
    if(r<=a[n*m-1]) k=n*m;
    for(int i=0; i<=n*m-1; i++){
        if(r<a[i] && r>a[i+1]){
            k=i+1;
            break;
        }
    }

    if(k<=n){
        cout<<1<<" "<<k;
        return 0;
    }
    int num = k/n;
    if(num%2!=0){
        cout<<num<<" "<<k%n;
        return 0;
    }
    else if(num%2==0){
        cout<<num+1<<" "<<k%n;
        return 0;
    }
    return 0;
}