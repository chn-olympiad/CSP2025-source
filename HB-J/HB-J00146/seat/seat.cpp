#include<bits/stdc++.h>
using namespace std;
int m,n,tgt,o,f;
int a[110],ma[12][12];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> m >> n;
    for(int i = 0;i<m*n;i++){
        cin >> a[i];
    }
    tgt = a[0];
    sort(a+0,a+m*n,cmp);
    for(int i = 1;i<=n;i++){
        if(i%2!=0){
            for(int j = 1;j<=m;j++){
                ma[i][j] = a[o];
                if(a[o] == tgt){
                    cout << i <<" "<< j;
                    f = 1;
                    break;
                }
                o++;
            }
        }else{

            for(int j = m;j>=1;j--){
                ma[i][j] = a[o];
                if(a[o] == tgt){
                    cout << i <<" "<< j;
                    f = 1;
                    break;
                }
                o++;
            }
        }

        if(f == 1){
            break;
        }
    }
    return 0;
}
