#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[15][15];
int man,k=1;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    man=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                b[j][i]=a[k];
                k++;
            }
        }else{
            for(int j=n;j>=1;j--){
                b[j][i]=a[k];
                k++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==man){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
