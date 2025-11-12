
#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat1.in","r",stdin);
    freopen("seat1.out","w",stdout);
    int n,m,h;
    cin>>n>>m;
    int a[n+1][m+1],b[n*m];
    for(int i=0;i<m*n;i++){
       cin>>b[i];
    }
    h=b[0];
    sort(b,b+n*m);
    int sum=0;
    for(int i=1;i<=n;i++){
        if(i%2!=0){
            for(int j=1;j<=m;j++){
                a[i][j]=b[n*m-sum-1];
                if(a[i][j]==h){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
                sum++;
            }
        }else{
            for(int j=m;j>=1;j--){
                a[i][j]=b[n*m-sum-1];
                if(a[i][j]==h){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
                sum++;
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
