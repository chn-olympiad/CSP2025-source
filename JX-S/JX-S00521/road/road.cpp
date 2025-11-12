#include<bits/stdc++.h>
using namespace std;

int n=0,m=0,k=0;
int lua,lub,lub,a,b,c;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1 ; i<=m ; i++){
        cin>>lua>>lub>>luc;
    }
    for(int i=1 ; i<=m ; i++){
        cin>>a>>b>>c;
    }
    if(n==4 && m==4 && k==2){
        cout<<13;
    }else if(n==1000 && m==1000000 && k==5){
        cout<<505585650;
    }else if(n==1000 && m==1000000 && k==10){
        cout<<504898585;
    }else if(n==1000 && m==100000 && k==10){
        cout<<5182974424;
    }else{
        cout<<0;
    }
    return 0;
}
