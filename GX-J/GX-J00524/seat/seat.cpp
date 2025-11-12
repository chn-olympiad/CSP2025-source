#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n = 0;
    int m = 0;
    cin>>n>>m;
    int num = n*m;
    int b[10][10];
    int x[100];
    int score = 0;
    for(int i=0;i<=num-1;i++){
        cin>>x[i];
    }
    score = x[0];
    int max_num = 0;
    for(int i=0;i<=num-1;i++){
        max_num = i;
        for(int j=i;j<=num-1;j++){
            if(x[i]<x[j]) {
                max_num = j;
            }
        }
        int flag = x[max_num];
        x[max_num] = x[i];
        x[i] = flag;
    }
    int z = 0;
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=m-1;j++){
            b[i][j]==x[z];
            z++;
        }
    }
    int res[10][10];
    int p=0;
    for(int i=0;i<=m-1;i++){
        if(i%2==0){
            for(int j=0;j<=n-1;j++){
                res[i][j] = x[p];
                p++;
            }
        }
        else{
            for(int j=n-1;j<=0;j--){
                res[i][j] = x[p];
                p++;
            }
        };
    }
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=m-1;j++){
            if(res[i][j]==score){
                cout<<i+1<<" "<<j+1;
                break;
            }
        }
    }
    return 0;
}
