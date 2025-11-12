#include<bits/stdc++.h>
using namespace std;
int a,b,c,g[4]={0},h=0,o[4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>b;
        int d[b+1][4],e[b+1][4];
        for(int j=1;j<=b;j++){
            for(int k=1;k<=3;k++){
                cin>>d[j][k];
                e[j][k]=k;
            }
            for(int k=1;k<3;k++){
                for(int l=i+1;l<=3;l++){
                    if(d[j][k]<d[j][l]){
                        swap(d[j][k],d[j][l]);
                        swap(e[j][k],e[j][l]);
                    }
                }
            }


        }
        int f=b/2;
        for(int j=1;j<=b;j++){
            if(e[j][1]==1){
                h+=b[j][1];
            }
            if(e[j][1]==2){
                h+=b[j][1];
            }
            if(e[j][1]==3){
                h+=b[j][1];
            }
        }
        o[a]=h;
        h=0;
    }

    return 0;
}
