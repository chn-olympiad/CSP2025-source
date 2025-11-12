#include <bits/stdc++.h>
using namespace std;
int main (){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,x,k;
    cin>>n>>m;
    int a[m*n+1];
    for(int i=0;i<m*n;i++){
        cin>>a[i];
    }
    x=a[0];
    for(int i=0;i<m*n-1;i++){
        for(int j=i;j<m*n-1;j++){
            if(a[j]<a[j+1]){
                k=a[j];
                a[j]=a[j+1];
                a[j+1]=k;
            }
        }
    }
   for(int i=0;i<m*n;i++){
        if(a[i]==x){
            k=i;
            break;
        }
    }
    cout<<k<<endl;
    int p,q;
    p=k/n+1;
    if(p%2==1){
        q=k-p*n+1+n;
    }else{
        q=k-p*n+1+n;
        q=n+1-q;
    }
    cout<<p<<' '<<q;
    return 0;
}
