#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r".stdin);
    freopen("seat.out","w".stdout);
    long long a,b,c[105],d,e[15][15],f[105],g=0;
    cin>>a>>b;
    for(int i=1;i<=a*b;i++){
        cin>>c[i];
        if(i==1){
            d=c[i];
        }
    }
    sort(c,c+a*b+1);
    for(int i=a*b,j=1;i>=1,j<=a*b;i--,j++){
        f[j]=c[i];
    }
    for(int i=1;i<=b;i++){
        if(i%2==1){
            for(int j=1;j<=a;j++){
                g++;
                e[i][j]=f[g];
                if(f[g]==d){
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        }
        else{
            for(int j=a;j>=1;j--){
                g++;
                e[i][j]=f[g];
                if(f[g]==d){
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
