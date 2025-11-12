#include <bits/stdc++.h>
using namespace std;

int n,m,b[15][15],nm,c[2],a[200];

void csp(int x){
    int s=0;
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++){
                s++;
                b[i][j]=a[nm-s+1];
                if(b[i][j]==x){
                    c[0]=i;
                    c[1]=j;
                }
            }
        }
        else{
            for(int j=n;j>=1;j--){
                s++;
                b[i][j]=a[nm-s+1];
                if(b[i][j]==x){
                    c[0]=i;
                    c[1]=j;
                }
            }
        }
    }
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    nm=n*m;
    for(int i=1;i<=nm;i++){
        cin>>a[i];
    }
    int a1=a[1];
    sort(a+1,a+nm+1);
    csp(a1);
    cout<<c[0]<<" "<<c[1];
    return 0;
}
