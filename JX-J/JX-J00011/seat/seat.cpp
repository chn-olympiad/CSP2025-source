#include<bits/stdc++.h>
using namespace std;
int a[1010],b[1010][1010],c[1010];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int cj=a[0];
    sort(a,a+n*m);
    for(int i=n*m-1;i>=0;i--){
        c[n*m-i]=a[i];
    }
    int k=1;
    for(int i=0;i<m;i++){
        if((i+1)%2!=0){
            for(int j=0;j<n;j++){
                b[j][i]=c[k];
                k++;
            }
        }
        else{
            for(int j=n-1;j>=0;j--){
                b[j][i]=c[k];
                k++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(b[i][j]==cj){
                cout<<j+1<<" "<<i+1;
                return 0;
            }
        }
    }
    return 0;
}

