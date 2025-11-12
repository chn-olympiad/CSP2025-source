#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,sum,c,r;
    int x[100000000]={};
    cin>>n>>m;
    sum=n*m;
    for(int i=0;i<sum;i++){
        cin>>x[i];
        for(int j=0;j<sum;j++){
            if(x[0]<x[j+1] && r<=m){
                r+=1;
                if(r>m){
                    c+=1;
                }
            else if(x[0]>x[j+1]){
                r=1;
                c=1;
            }
            }
        }
    }
    cout<<c<<r;
    return 0;
}

