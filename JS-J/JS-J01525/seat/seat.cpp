#include<bits/stdc++.h>
using namespace std;
int a[101][101];
int f[1001];
int dh[4]={1,0,-1,0},
    dl[4]={0,1,0,1};
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>f[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=1;
        }
    }
    int R=f[1];
    sort(f+1,f+n*m+1);
    int h=1,l=1,k=0;
    for(int i=n*m;i>0;i--){
        a[h][l]=f[i];
        if(f[i]==R){
            cout<<l<<" "<<h;
            break;
        }
        int th=h+dh[k],tl=l+dl[k];
        if(k%2==1){
            k++;
        }
        if(a[th][tl]!=1){
            k++;
            th=h+dh[k],tl=l+dl[k];
        }
        if(k>3)k-=4;
        h=th,l=tl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
