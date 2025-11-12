#include<bits/stdc++.h>
using namespace std;
int a[105],seat[15][15];
int n,m,r,cnt;
bool cmp(int x,int y){
    return x>=y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                cnt++;
                seat[i][j]=a[cnt];
                if(seat[i][j]==r){
                    cout<<j<<' '<<i;
                    return 0;
                }
            }
        }
        if(j%2==0){
            for(int i=n;i>=1;i--){
                cnt++;
                seat[i][j]=a[cnt];
                if(seat[i][j]==r){
                    cout<<j<<' '<<i;
                    return 0;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
