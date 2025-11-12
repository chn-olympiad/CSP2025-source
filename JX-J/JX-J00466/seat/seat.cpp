#include<bits/stdc++.h>
using namespace std;
int a[105];
int t[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int xiaot=a[1];
    sort(a+1,a+n*m+1);
    int p=n*m;
    for(int i=1;i<=m;i++){
            if(i%2!=0){
        for(int j=1;j<=n;j++){
            t[i][j]=a[p];
            p--;
        }
            }else{
            for(int j=n;j>=1;j--){
                t[i][j]=a[p];
                p--;
            }
            }
    }
        for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(t[i][j]==xiaot)
            cout<<i<<" "<<j;
        }
    }
    fcclose(stdin);
    fclose(stdout);
return 0;
}
