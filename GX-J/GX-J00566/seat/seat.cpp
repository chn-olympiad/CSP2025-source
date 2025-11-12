#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+1][m+1];
    int b[n*m+1];
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    int s=n*m+1,v=b[1];
    sort(b+1,b+n*m+1);
    for(int i=1;i<=n;i++){
        if(i%2==0){
            int h=1;
            for(int j=m;j>=1;j--){
                a[i][j]=b[s];
                s--;
                h++;
                if(b[s]==v){
                    cout<<i<<' '<<m-j;
                }
            }
        }
        else{
            for(int j=1;j<=m;j++){
                a[i][j]=b[s];
                s--;
                if(b[s]==v){
                    cout<<i<<' '<<j;
                }
            }
        }
    }
    return 0;
}
