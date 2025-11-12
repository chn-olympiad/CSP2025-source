#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","W",stdout);
    int c[1000],o,u,y;
    int a[100][100];
    int n,m,a1,l=0;
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>c[i];
        if(i==1){
            a1=c[i];
        }
        u=i;
    }
    sort(c+1,c+u+1);
    for(int i=1;i<=n;i++){
        if(i%2==0){
            for( int y=m;y>0;y--){
                l++;
                if(l!=n*m-1){
                    a[y][i]=c[u];
                    u--;
                }
            }
        }
        else{
            for( int y=1;y<=m;y++){
                l++;
                if(l!=n*m-1){
                    a[y][i]=c[u];
                    u--;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(i%2==0){
            for( int y=m;y>0;y--){
                if(a[y][i]<=a1){
                    cout<<i<<" "<<y;
                    return 0;
                }
            }
        }
        else{
            for( int y=1;y<=m;y++){
                if(a[y][i]<=a1){
                    cout<<i<<" "<<y;
                    return 0;
                }
            }
        }
    }

    return 0;
}
