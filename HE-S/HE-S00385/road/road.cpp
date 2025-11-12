#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,f[100100],g[100100],z[3][100100];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld",&a);
    scanf("%lld",&b);
    scanf("%lld",&c);
    for(int i=1;i<=b;i++){
        cin>>z[1][i]>>z[2][i]>>z[3][i];
    }
    for(int i=1;i<=b;i++){
        for(int j=i+1;j<=b;j++){
            if(z[3][i]>z[3][j]){
            swap(z[3][i],z[3][j]);
            swap(z[2][i],z[2][j]);
            swap(z[1][i],z[1][j]);
            }
        }
    }
    f[z[1][1]]=1;
    f[z[2][1]]=1;
    d+=z[3][1];
    while(a!=2){
        for(int i=2;i<=b;i++){
            if((f[z[1][i]]==1&&f[z[2][i]]==0)||(f[z[1][i]]==0&&f[z[2][i]]==1)){
                f[z[1][i]]=1;
                f[z[2][i]]=1;
                d+=z[3][i];
                a--;
                break;
            }
        }
    }
    cout<<d;
}
