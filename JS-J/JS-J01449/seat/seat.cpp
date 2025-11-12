#include<bits/stdc++.h>
using namespace std;
int a[1006],t[101][101];
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int num=a[1];
    sort(a+1,a+n*m+1,cmp);
    int cur=0,f=0,dx,dy;
    for(int i=1;i<=m;i++){
        if(i%2==0){
            for(int j=n;j>0;j--){
                t[j][i]=a[++cur];
                if(a[cur]==num){
                    dx=i,dy=j;
                    f=1;break;
                }
            }
        }
        else{
            for(int j=1;j<=n;j++){
                t[j][i]=a[++cur];
                if(a[cur]==num){
                    dx=i,dy=j;
                    f=1;break;
                }
            }
        }
        if(f) break;
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<t[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dx<<" "<<dy<<endl;
    return 0;
}