#include<bits/stdc++.h>
using namespace std;
int x[5005],ans;
int n;
inline void dg(int dep,int zc,int zd){
    if(dep>n){
        if(zc>zd*2){
            ans++;
        }
    }
    else{
        for(int i=0; i<=1; i++){
            if(i==0){
                dg(dep+1,zc,zd);
            }
            else {
                dg(dep+1,zc+x[dep],max(zd,x[dep]));
            }
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    
    
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>x[i];
    }
    dg(1,0,0);
    cout<<ans;
    return 0;
}