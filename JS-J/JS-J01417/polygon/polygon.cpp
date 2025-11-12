#include<bits/stdc++.h>
using namespace std;
int z[5000];
int u[5000];
int a;
int r=0;
void dfs(int m){



}

int main(){
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>z[i];
        u[i]=j[i]*2;
    }sort(z,z+a);
    for(int i=2;i<a;i++){
        int g=0;
        for(int j=0;j<i;j++){
            g+=z[i];
        }if(g==u)r++;
        else if(g>u){

        }
    }




    return 0;
}
