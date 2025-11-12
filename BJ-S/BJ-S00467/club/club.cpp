#include<bits/stdc++.h>
using namespace std;
int n;
int my[500005][5],m[5],pp[5];
void mm(int x,int y){
    m[y]+=my[x][y];
    pp[y]++;
}
void bj(int x,int y,int zb){
    if(my[zb][x]>my[zb][y]){
        mm(zb,x);
    }else if(my[zb][x]<my[zb][y]){
        mm(zb,y);
    }else if(pp[x]<pp[y]){
        mm(zb,x);
    }else {
        mm(zb,y);
    }
}
void bj2(int zb){
    if(my[zb][1]>my[zb][2]){
        bj(1,3,zb);
    }else if(my[zb][1]<my[zb][3]){
        bj(2,3,zb);
    }else if(pp[1]<pp[2]){
        
        bj(1,3,zb);
    }else {
        bj(2,3,zb);
    }
}
void check(int x){
    if(pp[1]>n/2){
        bj(2,3,x);
    }else if(pp[2]>n/2){
        bj(1,3,x);
    }else if(pp[3]>n/2){
        bj(1,2,x);
    }else{
        bj2(x);
    }
}
void mmain(){
    m[1]=0,m[2]=0,m[3]=0,pp[1]=0,pp[2]=0,pp[3]=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>my[i][j];
        }
    }for(int i=1;i<=n;i++){
        check(i);
    }cout<<m[1]+m[2]+m[3];
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
cin>>t;
    while(t--){
        mmain();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
