#include<bits/stdc++.h>
using namespace std;
int a[101];
int b[11][11];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,k;
    cin>>n>>m;
    cin>>k;
    a[1]=k;
    int t=1,d=1;
    for(int i=1;i<=n;i++){
        if(d%2==0){
            for(int j=m;j>=1;j--){
                b[i][j]=t;
                t++;
            }
            d++;
        }else{
            for(int j=1;j<=m;j++){
                b[i][j]=t;
                t++;
            }
            d++;
        }
    }
    for(int i=2;i<=n*m;i++){
            cin>>a[i];
    }
    int h=n*m;
    sort(a+1,a+h+1,cmp);
    for(int i=1;i<=h;i++){
        if(a[i]==k){
            for(int x=1;x<=n;x++){
                for(int y=1;y<=m;y++){
                    if(b[x][y]==i){
                        cout<<x<<" "<<y;
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}
