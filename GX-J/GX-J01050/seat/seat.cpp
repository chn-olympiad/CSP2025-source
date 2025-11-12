#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int a1[n*m+1],a[n+1][m+1];
for(int i=1;i<=n*m;i++){
    cin>>a1[i];
}
int aa=a1[1];
sort(a1+1,a1+1+n*m);
int q=1;
    for(int j=m;j<=1;j++){
        if(j%2==1){
        for(int i=n;i>=i;i--){
                a[i][j]=a1[q];
                q++;
                }
                }
            else if(j%2==0){
                for(int i=1;i<=n;i++){
                a[i][j]=a1[q];
                q++;

                }
                }
}
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(aa==a[i][j]){
            cout<<i<<" "<<j;
        }
    }
}




fclose(stdin);
fclose(stdout);
return 0;
}
