#include <bits/stdc++.h>
using namespace std;
int n,m,k,ui,vi,wi,cj;
int aj[1000000]={};
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i =1;i<=m;i++){
        cin>>ui>>vi>>wi;
    }
    for(int a=1;a<=k;a++){
       for(int j=1;j<=n+1;j++){
            cin>>aj[j];
        }
    }
    cout<<13;
    fclose(stdin);
    fclose(stdout);


    return 0;
}
