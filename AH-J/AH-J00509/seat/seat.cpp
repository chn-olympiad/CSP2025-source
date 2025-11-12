#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>n>>m;
    int a[m*n];
    for(int i=0;i<m*n;i++){
        cin>>a[i];
    }
    int w=a[1];

    for(int i=0;i<=m;i++){
        for(int j=0;j<n;j++){
            if(a[i]>a[i+1]){
                int q;
                q=a[i];
                a[i]=a[i+1];
                a[i+1]=q;
            }
        }
    }

    bool z=1;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(a[i*j]==w){
                if(i%2==1){
                    cout<<i+1<<" "<<j+1;
                }
                else{
                    cout<<i+1<<" "<<n-j;
                }
                z=0;
                break;
            }
        }
        if(z==0){
            break;
        }
    }
}
