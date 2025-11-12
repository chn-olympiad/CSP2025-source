#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("p2.in","r",stdin);
    freopen("p2.out","w",stdout);
    int m,n,a[110],b[20][20],r,d=1,x,y;
    cin>>n>>m;
    for(int k=1;k<=n*m;k++){
        cin>>a[k];
    }
    r=a[1];
    sort(a+1,a+1+m*n);
    reverse(a+1,a+1+m*n);
    int i=1,j=1;
    for(int k=1;k<=m*n;k++){
        if(r==a[k]){
            r=k;
            break;
        }
    }
    for(int k=1;k<=r;k++){
        b[i][j]=a[k];
        if(k==r){
            x=i;
            y=j;
        }
        if(d==-1&&i==1){
            d=1;
            j++;
            continue;
        }
        if(d==1&&i==n){
            d=-1;
            j++;
            continue;
        }
        i+=d;
    }
    cout<<y<<" "<<x;
    return 0;
}