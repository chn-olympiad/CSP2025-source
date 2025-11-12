#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[(n*m)+1];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int q=a[1];
    int b[n+1][m+1];
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=n*m;j++){
            if(a[j]<=a[j+1]){
            swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i%2==0){
                for(int k=n;k>=1;k--){
                    for(int l=((i-1)*m)+1;l<=i*m;l++)
                        b[i][k]=a[((i-1)*m)+1+(n-k)];
                }
                break;
            }
            b[i][j]=a[j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(b[i][j]==q){
                cout<<i<<" "<<j;
                break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
