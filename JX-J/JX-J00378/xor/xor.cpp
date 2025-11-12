#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],dp[N];
int nor(int x,int y){
    int nx[100],ny[100],ix=0,iy=0;
    memset(nx,0,sizeof(nx));
    memset(ny,0,sizeof(ny));
    while(x>0){
        nx[++ix]=x%2;
        x/=2;
    }
    while(y>0){
        ny[++iy]=y%2;
        y/=2;
    }
    for(int i=1;i<=max(ix,iy);i++){
        if(nx[i]==ny[i])nx[i]=0;
        else nx[i]=1;
    }
    int d=0;
    for(int i=1;i<=max(ix,iy);i++){
        d+=pow(2,i-1)*nx[i];
    }
    return d;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n&&cin>>a[i];i++){
        if(i>1)dp[i]=nor(dp[i-1],a[i]);
        else dp[i]=a[i];
    }
    int cnt=0;
    int L=1;
    for(int R=1;R<=n;R++){
        for(int j=L;j<=R;j++){
            if(  (R==j&&a[R]==k) || (nor(dp[R],dp[j-1])==k)  ){
                cnt++;
                //cout<<L<<" "<<R<<"\n";
                L=R+1;
                break;
            }
        }
    }
    cout<<cnt;
    
    return 0;
}

/*
2 1 0 3
2 3 3 0 

0:00
1:01
2:10
3:11


20 1
1 0 1 1 0 0 0 1 1 1  1  1  1  0  0  1  1  1  1  1 
1 1 0 1 1 1 1 0 1 0  1  0  1  1  1  0  1  0  1  0 
1 2 3 4 5 6 7 8 9 X X1 X2 X3 X4 X5 X6 X7 X8 X9 XX

1 1
2 3
4 4
5 8
9 9
10 10
11 11
12 12
13 13
14 16
17 17
18 18
19 19
20 20

0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1




*/