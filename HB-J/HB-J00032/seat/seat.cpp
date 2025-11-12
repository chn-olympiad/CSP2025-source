#include <bits/stdc++.h>
using namespace std;
int g[114];
int n,m;
bool cmp(int &x,int &y){
    return x>y;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m*n;i++){
        cin>>g[i];
    }
    int ri=g[0];
    sort(g,g+m*n,cmp);
    int dex=0;
    for(int i=0;i<m*n;i++){
        if(ri==g[i]){
            dex=i+1;
        }
    }
    //for(int i=0;i<m*n;i++){
    //    cout<<g[i]<<' ';
    //}
    int row=ceil((double)dex/n);
    int col=(((dex%n)==0)?n:dex%n);
    if(row&1){
        cout<<row<<" "<<col;
    }else{
        cout<<row<<" "<<n-col+1;
    }
    return 0;
}
