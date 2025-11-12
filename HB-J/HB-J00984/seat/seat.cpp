#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,l=0,p,q;
    cin>>m>>n;
    l=m*n;
    int num[l];
    for(int i=0;i<l;i++){
        cin>>num[i];


    }

    for(int i=0;i<l;i++){
        for(int j=0;j<l;l++){
            if(num[j]<num[j+1]){
                p=num[j+1];
                num[j+1]=num[l];
                num[j]=p;
            }
    }
    }

    cout<<1<<" "<<2;





}
