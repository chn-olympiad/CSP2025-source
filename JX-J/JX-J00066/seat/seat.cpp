#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,q,mm;
    cin>>n>>m;
    int map[m][n]={0},zs=n*m;
    int cj[zs];
    for(int i=0;i<zs;i++){
        cin>>cj[i];
    }
    q=cj[0];
    sort(cj,cj+zs);
    for(int i=0;i<=zs;i++){
        if(cj[i]==q){
            mm=zs-i;
        }
    }
    int zong=mm%(n*2),lie=mm/m;
    if(zong<=n){
        zong=zong;
    }else{
        zong=zong+1-n;
    }
    if(lie==0){
        lie=lie;
    }else{
        lie=lie+1;
    }
    cout<<lie<<" "<<zong;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
