#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    int a[12][12],fs[105],xR;
    cin>>n>>m;
    for(int i=0;i<m*n;i++){
        cin>>fs[i];

    }
    xR=fs[0];
    int k=m*n-1;
    sort(fs,fs+m*n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            a[i][j]=fs[k];
            k--;
        }
        i++;
        for(int j=n-1;j>=0;j--){
            a[i][j]=fs[k];
            k--;
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==xR){
                cout<<i+1<<' '<<j+1;
                return 0;
            }
        }
    }
    return 0;
}
