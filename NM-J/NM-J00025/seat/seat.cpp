#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,p,b[101]={0},te;
    cin>>n>>m;
    cin>>p;
    for(int i=1;i<=n*m-1;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n*m-1;i++){
        for(int j=1;j<=n*m-1;j++){
            if(b[j]<=b[j+1]){
                te=b[j];
                b[j]=b[j+1];
                b[j+1]=te;
                te=0;
            }
        }
}
    int shu=n*m;
    for(int i=1;i<=n*m-1;i++){
        if(p>b[i]){
            shu=i;
        }
    }
    for(int i=1;i<=n;i++){
        if(i%2==1){
        for(int j=1;j<=m;j++){
            shu--;
            if(shu==0){
                cout<<i<<" "<<j;
            }
            }
        }else{
            for(int j=m;j>=1;j--){
            shu--;
            if(shu==0){
                cout<<i<<" "<<j;
            }
        }
    }
    }
    return 0;
}
