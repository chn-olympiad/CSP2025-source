#include<iostream>
#include<algorithm>
using namespace std;
int m,n,a;
int sit[15][15],sc[1000];
bool cmp(int x,int y){
    return x < y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m ;
    a=m*n;
    cin >> sc[0];
    int num=sc[0];
    for(int i=1;i<a;i++){
        cin >> sc[i];
    }
    sort(sc+0,sc+a+1,cmp);
    for(int i=1;i<=m;i++){
        if(i%2 == 1){
            for(int j=1;j<=n;j++){
                sit[i][j]=sc[(i-1)*n+j];
            }
        }
        else{
            for(int j=n;j>=1;j--){
                sit[i][j]=sc[i*n-j];
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(sit[i][j]==num){
                cout << j <<' ' << i;
                return 0;
            }
        }
    }

    return 0;
}
