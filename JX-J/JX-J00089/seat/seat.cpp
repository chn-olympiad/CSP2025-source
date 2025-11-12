#include<bits/stdc++.h>
using namespace std;

int n,m,a[200],b[200];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n*m;i++){
        scanf ("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+n*m+1);
    int pos=0;
    for (int i=1;i<=n*m;i++){
        if (a[1]==b[i]){
            pos=n*m-i+1;
            break;
        }
    }
    int nx,ny=pos/n;
    if (pos%n!=0) ny++;
    if (ny%2==1){
        if (pos%n==0){
            nx=n;
        }
        else{
            nx=pos%n;
        }
    }
    else{
        if (pos%n==0){
            nx=1;
        }
        else{
            nx=n-(pos%n)+1;
        }
    }
    printf("%d %d",ny,nx);
    return 0;
}
