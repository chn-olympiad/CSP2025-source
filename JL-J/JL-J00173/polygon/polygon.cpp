#include<bits/stdc++.h>
using namespace std;
int n,ans,sx=1;
vector<int>vx(5010);
map<int,int>v;
void sc(int p,int s,int mn){
    if (p==n){
        if (s>2*mn){ans=(ans+1)%998244353;}
        if (s+vx[p]>2*max(mn,vx[p])){ans=(ans+1)%998244353;}

        return;
    }
    sc(p+1,s,mn);
    sc(p+1,s+vx[p],max(mn,vx[p]));
}
int main(){
    freopen("polygon.cpp","r",stdin);
    freopen("polygon.cpp","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>vx[i];
        if (vx[i]!=1)sx=0;
    }
    sort(vx.begin()+1,vx.begin()+1+n);
    if (n==3){
        if (vx[1]+vx[2]+vx[3]>2*max(max(vx[1],vx[2]),vx[3]))ans=1;
    }
    else{
        sc(1,vx[1],vx[1]);
        sc(1,0,0);
    }
    cout<<ans;
}
