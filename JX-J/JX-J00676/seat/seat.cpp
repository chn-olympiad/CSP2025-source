#include<bits/stdc++.h>
using namespace std;
int a[1009][1009];
int p[1009];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>p[i];
    }
    int s=p[1];
    sort(p+1,p+1+n*m);
    int z=n*m;

    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                if(s==p[z])cout<<i<<" "<<j;
                a[i][j]=p[z--];
            }
        }else {
            for(int j=n;j>=1;j--){
                if(s==p[z])cout<<i<<" "<<j;
                a[i][j]=p[z--];
            }
        }
    }
    return 0;
}
