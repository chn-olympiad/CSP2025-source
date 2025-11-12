#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105],a1[105][105],x=0;
    bool f=1;
    cin>>n>>m;
    for(int i=0;i<m*n;i++) cin>>a[i];
    for(int i=0;i<m*n;i++){
        for(int j=0;j<m*n-1;j++){
            if(a[j]<a[j+1]){
                int b=a[j];
                a[j]=a[j+1];
                a[j+1]=b;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            a1[j][i]=a[x];
            x++;
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(j%2==0){
                cout<<a1[i][j]<<" ";
            }
            else{
                cout<<a1[n-i-1][j]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
