#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[200];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int x=a[1],y;
    for(int i=1;i<=n*m;i++){
        for(int j=i;j<=m*n;j++){
            if(a[i]<a[j]){
                int q=a[i];
                a[i]=a[j];
                a[j]=q;
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            y=i;
            break;
        }
    }
    int p,q;
    if(y%(2*n)<n){
        p=y/n+1;
        q=y%(2*n);
    }else if(y%(2*n)==0){
        p=y/n;
        q=1;
    }else if(y%(2*n)>n){
        p=y/n+2;
        q=n-(y%(2*n)-n)+1;
    }else if(y<2*n&&y>n){
        p=2;
        q=n-(y-n)+1;
    }else if(y<=n){
        p=1;
        q=y;
    }
    cout<<p<<" "<<q;
    return 0;
}
