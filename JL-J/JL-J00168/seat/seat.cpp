#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[111];
int r;
int ma[11][11];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    r=a[1];
    for(int j=1;j<=m*n;j++){
        for(int i=2;i<=m*n;i++){
            if(a[i]>a[i-1]){
                swap(a[i],a[i-1]);
            }
        }
    }
    int which=1;
    for(int i=1;i<=m;i++){
        if(m%2==1){
            for(int j=1;j<=n;j++){
                ma[j][i]=a[which];
                if(a[which]==r){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
                which++;
            }
        }
        else if(m%2==0){
            for(int j=n;j>=1;j--){
                ma[j][i]=a[which];
                if(a[which]==r){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
                which++;
            }
        }
    }
    return 0;
}
