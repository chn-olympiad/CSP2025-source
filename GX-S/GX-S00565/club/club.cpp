#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long a,b,c,j1=0,j2=0,j3=0,e[100001],d[100001],f[100001],g[100001];
    cin>>a;
    for(int i=1;i<=a;i++){
    cin>>b;
    for(int j=1;j<=b;j++){
    cin>>e[j]>>d[j]>>f[j];
    }
    for(int j=1;j<=b;j++){
    if(e[j]>d[j]>f[j]){j1=j1+e[j];}
    else{if(e[j]>f[j]>d[j])j1=j1+e[j];}
    if(d[j]>e[j]>f[j]){j2=j2+d[j];}
    else{if(d[j]>f[j]>e[j])j2=j2+d[j];}
    if(f[j]>d[j]>e[j]){j3=j3+f[j];}
    else{if(f[j]>e[j]>d[j])j3=j3+f[j];}
    }
    cout<<j1+j2+j3;
    }
    return 0;
}
