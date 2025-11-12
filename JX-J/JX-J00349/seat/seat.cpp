#include<bits/stdc++.h>
using namespace std;
int m,n,x;
int b[405],c[21][21],bi;
bool cm(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>x;
    b[0]=x;
    for(int i=1;i<n*m;i++){
        cin>>b[i];
    }
    sort(b,b+bi,cm);
    for(int i=0;i<m;i++){
        if(i%2==1){
            for(int l=0;l<n;l++){
                c[i][l]=b[bi];
                bi++;
            }
        }
        else{
            for(int l=n-1;l>=0;l--){
                c[i][l]=b[bi];
                bi++;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int l=0;l<n;l++){
            if(c[i][l]==x){
                cout<<i+1<<" "<<l+1;
                return 0;
            }
        }
    }
    return 0;
}
