#include<bits/stdc++.h>
using namespace std;
int n,m;
int seat[15][15];
int k[120];
int dy[2]={1,-1};
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>k[i];
    }
    int mine=k[1];
    sort(k+1,k+n*m+1,cmp);
    int x=1,y=1;
    int d=0;
    int c,r;
    for(int i=1;i<=n*m;i++){
        seat[x][y]=k[i];
        if(seat[x][y]==mine){
            c=x,r=y;
            break;
        }
        if(y+dy[d]>n||y+dy[d]<1){
            d=(d+1)%2;
            x++;
        }else{
           y=y+dy[d];
        }
    }
    cout<<c<<" "<<r<<endl;
    return 0;
}
