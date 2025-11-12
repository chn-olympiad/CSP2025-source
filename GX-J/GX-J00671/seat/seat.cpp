#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;

     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
           cin>>a[i][j];
        }
    }
    int r_cj=a[1][1],r_cj_id=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]<a[j])swap(a[i],a[j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(r_cj==a[i][j])r_cj_id=r_cj_id+i+j;
        }
    }
    int r=r_cj_id/n+r_cj_id%n;
    int c=r_cj_id&m;
    cout<<r<<" "<<c;
    return 0;
}
