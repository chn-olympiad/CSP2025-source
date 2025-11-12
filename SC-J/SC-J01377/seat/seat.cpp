#include<bits/stdc++.h>
using namespace std;
int n,m,num,nmy,pm=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>nmy;
    for(int i=2;i<=n*m;i++){
        cin>>num;
        if(num>nmy)pm++;
    }
    int ny,my;
    ny=pm/n;
    pm=pm%n;
    if(pm!=0){
        ny++;
        if(ny%2){
            my=pm;
        }else{
            my=n-pm+1;
        }
    }else{
        if(ny%2){
            my=m;
        }
        else{
            my=1;
        }
    }
    cout<<ny<<" "<<my;
    return 0;
}
