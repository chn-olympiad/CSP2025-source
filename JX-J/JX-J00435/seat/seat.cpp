#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,k=0,we=0,nm=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int qw=a[0][0];
    if(n==1&&m==1){
        cout<<1<<" "<<1;
        return 0;
    }
    if(n==1){
        for(int i=0;i<m;i++){
            k=max(qw,a[i][1]);
            if(k==qw){
               we++;
            }
        }
        cout<<we<<" "<<1;
    }
    if(m==1){
        for(int i=0;i<m;i++){
            k=max(qw,a[1][i]);
            if(k==qw){
               nm++;
            }
        }
        cout<<1<<" "<<nm;
    }
}
