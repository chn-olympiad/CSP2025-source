#include <bits/stdc++.h>
using namespace std;
int n,m,a[15],f[15][15];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    int leng=n*m;
    for(int i=1; i<=leng; i++){
        cin >> a[i];
    }int k=a[1];
    sort(a+1,a+1+leng,cmp);
    int t=0;
    for(int j=1; j<=m; j++){
        if(j%2==1){
            for(int i=1; i<=n; i++){
                t++;
                f[i][j]=a[t];
                if(a[t]==k){
                    cout << j << " " << i;
                }
            }
        }else{
            for(int i=n; i>=1; i--){
                t++;
                f[i][j]=a[t];
                if(a[t]==k){
                    cout << j << " " << i;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
