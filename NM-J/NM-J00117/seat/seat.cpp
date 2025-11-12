#include<bits/stdc++.h>
using namespace std;
long long a[110];
int pai[110];
int zuo[15][15];
int n,m;
int paixu(int x){
    for(int i=1;i<=x;i++){
        for(int j=1;j<=x;j++){
            if(a[j]>pai[i]){
                pai[i]=a[j];
            }
        }
    }
}
int c=1;
int zuowei(int x){
    for(int i=1;i<=n;i++){
            if(i%2==0){
                for(int j=m;j>=1;j--){
                    pai[c]=zuo[i][j];
                    c++;
                    if(pai[c]==x){
                        cout<<i<<" "<<j;
                        return 0;
                    }
                }
            }else{
               for(int j=1;j<=m;j++){
                    pai[c]=zuo[i][j];
                    c++;
                    if(pai[c]==x){
                        cout<<i<<" "<<j;
                        return 0;
                    }
                }
            }
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int q=a[1];
    paixu(n*m);
    zuowei(q);
}
