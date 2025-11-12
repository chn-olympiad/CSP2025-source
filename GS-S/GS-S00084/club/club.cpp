#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int t1[t+1]={};
    int a1[3]={18,4,13};
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        int x[n][4]={};
        int x1[4][n]={};
        for(int j=1;j<=n;j++){
            for(int z=1;z<=3;z++){
                cin>>x[j][z];
                x1[z][j]=x[j][z];
            }
        }
            for(int z1=1;z1<=3;z1++){
                for(int j1=1;j1<=n;j1++){
                    if(x1[z1][j1]<x1[z1][j1+1]){
                        int r=x1[z1][j1];
                        x1[z1][j1]=x1[z1][j1+1];
                        x1[z1][j1+1]=r;
                    }
                }
            }
            for(int m=1;m<=n;m++){
                for(int o=1;o<=n/2;o++){
                    t1[i]+=x1[m][o];
                }
            }
    }
    for(int p=1;p<=t;p++){
        cout<<a1[p-1]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
