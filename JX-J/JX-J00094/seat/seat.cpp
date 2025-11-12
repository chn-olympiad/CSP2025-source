#include<bits/stdc++.h>
using namespace std;
bool cmp(int a1,int a2){
    return a1>a2;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int mp[1010] = {};
    for(int i = 1;i<=n*m;i++){
        cin>>mp[i];
    }
    int minf = mp[1];
    sort(mp+1,mp+n*m+1,cmp);
    int id = 1;
    for(int i = 1;i<=n*m;i++){
        //cout<<mp[i]<<" ";
        if(mp[i] == minf){
            id = i;
            //break;
        }
    }
    //cout<<id<<" "<<n;
    int lie = (id-1)/n+1;
    int hang = (id-1)%n+1;
    if(lie%2 == 0){
        hang = n-hang+1;
    }else{
        hang = hang;
    }
    cout<<lie<<" "<<hang;
}
