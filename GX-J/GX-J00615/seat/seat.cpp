#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    int score=a[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int l=i,h=j;
            while(l<=n){
                if(a[i][j]<a[l][j]) a[i][j]=a[l][j];
                l++;
            }
            while(h<=m){
                if(a[i][j]<a[i][h]) a[i][j]=a[i][h];
                h++;
            }
        }
    }
    int c,r;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i][j]==score){
                c=i;
                r=j;
                cout<<c<<" "<<r;
                break;
            }
        }
    }
    return 0;
}
