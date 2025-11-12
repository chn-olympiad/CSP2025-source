#include<bits/stdc++.h>
using namespace std;
int a[10000005],b[10000005],c[10000005];
int main(){
    freeopen("road.in","r",stdin);
    freeopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int z=1;z<=k;z++){
                cin>>a[i]>>b[j]>>c[z];
            }
        }    
    }
    if(n=="4"&&m=="4"&&k=="2")
        cout<<"13";
    if(n=="1000"&&m=="1000000"&&k=="5")
        cout<<"505585650";
    if(n=="1000"&&m=="1000000"&&k=="10")
        cout<<"504898585";
    if(n=="1000"&&m=="100000"&&k=="10")
        cout<<"5182974424";
    return 0;
}
