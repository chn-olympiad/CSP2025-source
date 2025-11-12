#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=105;
int n,m,cnt,t=0,x=1,y=1,ansx,ansy,a[N],s[M][M];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    cnt=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        s[x][y]=a[++t];
        if(x==n&&y%2==1){
            y=y+1;
        }else if(x==1&&y%2==0){
            y=y+1;
        }else if(y%2==1){
            x++;
        }else x--;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]==cnt){
                ansx=i,ansy=j;
            }
            //cout<<s[i][j]<<' ';
        }
        //cout<<endl;
    }
    cout<<ansy<<' '<<ansx;
    return 0;
}
/*
20 11 10 1
19 12  9 2
18 13  8 3
17 14  7 4
16 15  6 5

2 2
98 99 100 97
*/
