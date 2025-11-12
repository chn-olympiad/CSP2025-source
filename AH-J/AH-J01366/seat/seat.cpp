#include<bits/stdc++.h>
using namespace std;
int a[110],xiaop;
int b[15][15];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1){
            xiaop=a[i];
        }
    }
    sort(a+1,a+n*m+1,cmp);
    int p=1,x=1,y=1;
    for(int i=1;i<=n*m;i++){
        b[x][y]=a[i];
        if(x==n&&p==1){
            y++;
            p=-1;
        }else if(x==1&&p==-1){
            y++;
            p=1;
        }else{
            x=x+p;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==xiaop){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
