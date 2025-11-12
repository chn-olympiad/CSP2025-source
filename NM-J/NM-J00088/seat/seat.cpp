#include<bits/stdc++.h>
using namespace std;
int a[105],b[105][105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdin);
    int n,m,nm,c,r,i,j,t,bj=1,k=1;
    cin >> n >> m;
    nm=n*m;
    for(i=1;i<=nm;i++){
        cin >> a[i];
    }
    for(i=1;i<=nm;i++){
        for(j=1;j<nm;j++){
            if(a[j]<a[j+1]){
                if(a[bj]==a[j]){
                    bj++;
                }
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    for(i=1;i<=m;i++){
        if(i%2==1){
            for(j=1;j<=n;j++){
                if(k==bj){
                    cout << i << " " << j;
                    return 0;
                }
                k++;
            }
        }else{
            for(j=n;j>=1;j--){
                if(k==bj){
                    cout << i << " " << j;
                    return 0;
                }
                k++;
            }
        }
    }
    return 0;
}

