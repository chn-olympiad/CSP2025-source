#include<bits/stdc++.h>
using namespace std;
bool cmp(int n,int m){
    return n>m;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int nu[n*m];
    for(int i=0;i<n*m;i++){
        cin>>nu[i];
    }
    int r=nu[0],rxb=0;
    int k=n*m;
    for(int i=0;i<n*m;i++){
        for(int j=i;j<n*m;j++){
            if(nu[i]<nu[j]){
                if(i==0) rxb=j;
                if(j==0) rxb=i;
                swap(nu[i],nu[j]);
            }
        }
    }
    int in=0;
    int a[n][m];
    int flag=0;
    for(int j=0;j<m;j++){
        if(!flag){
            for(int i=0;i<n;i++){
                a[i][j]=nu[in];
                in++;
            }
            flag=1;
        }else{
            for(int i=n-1;i>=0;i--){
                a[i][j]=nu[in];
                in++;
            }
            flag=0;
        }
    }
    in=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==r){
                cout<<j+1<<" "<<i+1;
                break;
            }
            in++;
        }
    }
    return 0;
}
