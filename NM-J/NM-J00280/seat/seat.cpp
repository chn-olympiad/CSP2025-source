#include<bits/stdc++.h>
using namespace std;
int n,m;
int p;
int a[10005];
int aa[105][105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    p=a[1];
    sort(a+1,a+(n*m)+1);
    int i=1,j=1;
    int di=1;
    for(int q=n*m;q>=1;q--){
        aa[i][j]=a[q];
        if(i+di>n){
            di=-1;
            j++;
        }
        else if(i+di<1){
            di=1;
            j++;
        }
        else i+=di;

    }
    int ax,ay;
    for(int x=1;x<=n;x++){
        for(int y=1;y<=m;y++){
            if(aa[x][y]==p){
                ax=x;ay=y;
                break;
            }
        }
    }
    cout<<ax<<" "<<ay;
    return 0;
}
