#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long cj[n][m];
    long long zw[n][m];
    int r=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>cj[i][j];
            zw[i][j]=0;
            r=cj[0][0];
        }
    }
    for(int y=0;y<m;i++){
        for(int x=0;x<n;j++){
            if(cj[x][y]>r){
                cj[x][y]=zw[x][y];
            }
        }
    }
    for(int y=0;y<m;i++){
        for(int x=0;x<n;j++){
            if(r>=cj[x][y]){
                r=zw[x][y];
            }
        }
    }
    for(int y=0;y<m;y++){
        for(int x=0;x<n;x++){
            if(zw[x][y]=r){
                cout<<x<<" "<<y;
                break;
            }
        }
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
