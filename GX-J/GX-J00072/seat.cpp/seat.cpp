#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,cj;
    cin>>n>>m;
    int a[n*m],b[n][m];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    cj=a[0];
    for(int i=0;i<n*m;i++){
        for(int j=i+1;j<n*m;j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=0;i<m;i++){
        int c=0;
        if(i%2==0){
            for(int j=n-1;j>=0;j--){
                b[j][i]=a[c];
                c++;
            }
        }
        else{
            for(int j=0;j<n;j++){
                b[j][i]=a[c];
                c++;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(b[j][i]==cj){
                cout<<i+1<<" "<<j+1;
            }
        }
    }
    return 0;
}
