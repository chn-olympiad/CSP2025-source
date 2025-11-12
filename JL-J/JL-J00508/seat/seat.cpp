#include<bits/stdc++.h>
using namespace std;
int m,n,a[100],k,b[100],i,h;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    for(i=0;i<m*n;i++)
        cin>>a[i];
    a[1]=k;
    for(i=0;i<m*n;i++){
        for(int j=0;j<m*n;j++){
            if(a[i+1]>a[i]){
                b[i]=a[i+1];
                b[i+1]=a[i];
            }
        }
    }
    for(i=0;i<m*n;){
        if(b[i]==k) break;
        i++;
    }
    k=i/m;
    k+=1;
    i%=k;
    if(k%2==1){
        cout<<i+1<<' '<<k+1;
    }
    else
        cout<<i+2<<' '<<k-1;
    return 0;
}
