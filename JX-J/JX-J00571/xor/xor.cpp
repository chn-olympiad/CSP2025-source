#include<bits/stdc++.h>
using namespace std;
int n,k,a[510000],b[510000],c;
int rjz(int x){
    int y=0,z=x;
    if (x==0)return 0;
    if (x%2==0)y=1;
    while(x){
        y=x%2+y*10;
        x=x/2;
    }
    if(z%2==0)return y/10;
    return y;
}
int pd(int x,int y){
    int z=0;
    while(max(x,y)){
        z=z*10+(x%2+y%2)%2;
        x=x/10;
        y=y/10;
    }
    if(z==k)c++;
    return z;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.ans","w",stdout);
    cin>>n>>k;
    k=rjz(k);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=rjz(a[i]);
    }
    for(int i=1;i<=n;i++){
		for(int o=n;o>=1;o--){
            b[o]=pd(b[o+1],a[o]);
            if(b[o]==k){
                c++;
            }
        }
    }
    cout<<c/2;
    return 0;
}
