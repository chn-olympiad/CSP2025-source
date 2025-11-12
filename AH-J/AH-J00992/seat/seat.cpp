#include<bits/stdc++.h>
using namespace std;
int n,m,i,j;
int t,e,d;
int my;
int g[150];
int a[15][15];
int dx[6]={1,-1};
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    t=n*m;
    for(i=1;i<=t;i++){
        cin>>g[i];
    }
    my=g[1];
    sort(g+1,g+1+t,cmp);
    e=1;
    i=1;j=1;
    d=0;
    while(1){
        //cout<<i<<" "<<j<<" "<<dx[d]<<endl;
        if(g[e]==my){
            break;
        }else{
            if(!(i+dx[d]<=n&&i+dx[d]>=1)){
                d++;
                d=d%2;
                j++;
            }else{
                i=i+dx[d];
            }
        }
        e++;
    }
    cout<<j<<" "<<i;
    return 0;
}
