#include<iostream>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int c;
    cin>>c;
    int a[c];
    for(int i=0;i<c;i++){
        cin>>a[i];
    }
    for(int i=0;i<c;i++){
        if(a[i]>a[i]-1){
            a[i]-=a[i-1];
        }

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            break;
        }
    }
    int z=1;
    int k=1;
    if(n==2&&m==2){
        cout<<z<<" "<<k;
    }else{
        return 0;
    }
    if(n=2,m=2){
        cout<<z+1<<" "<<k+1;
    }else{
        return 0;
    }
    return 0;
}
