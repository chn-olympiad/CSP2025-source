#include<iostream>
using namespace std;
int a[100][4]={0},b[100][6]={0};
void pfintfcheng(int d){
    for(int i=1;i<=d;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }
    }
}
void pfintfcun(int k){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=5;j++){
            cin>>b[i][j];
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    pfintfcheng(m);
    printfcun(k);
	return 0;
}
