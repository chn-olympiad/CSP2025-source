#include<iostream>
#include<cstring>
using namespace std;
int e[10100],f[10100][10100];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b,c,d=0;
    cin>>a>>b;
    for(int i=1;i<=a*b;i++){
        cin>>e[i];
    }
    c=e[1];
    for(int i=a*b;i>=1;i--){
        for(int j=a*b;j>=1;j--){
            if(e[j]>e[j-1]){
                swap(e[j],e[j-1]);
            }
        }
    }
    for(int i=1;i<=a;i++){
        if(i%2==1){
            for(int j=1;j<=b;j++){
                f[i][j]=e[d];
                d++;
            }
        }
        else{
            for(int u=b;u>=1;u--){
                f[i][u]=e[d];
                d++;
            }
        }
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(f[i][j]==c){
                cout<<i<<" "<<j;
            }
        }
    }
}
