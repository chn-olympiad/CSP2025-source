#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int c[n][m];
    int a[n*m];
    int ans=a[0];
    int x,y;
    for(int i = 0;i<m*n;i++){
        cin>>a[i];
    }
    for(int i = 0;i<n*m;i++){
        for(int j = 0;i<n*m;i++){
            if(a[i*j]<a[i*j+1]){
                int n=a[i*j];
                a[i*j]=a[i*j+1];
                a[i*j+1]=n;

            }
        }
    }
    for(int i = 0;i<m*n;i++){
        for(int j = 0;j<n;j++){
            for(int k = 0;k<m;k++){
                c[j+1][k] = a[i];
            }
        }
    }
    for(int i = 0;i<m*n;i++){
        for(int j = 0;j<n;j++){
            for(int k = 0;k<m;k++){
                if(c[j+1][k]==ans){
                    x = j+1;
                    y = k;
                    break;



                }
            }
        }
    }
    cout<<x<<" "<<y-32763;
    return 0;
}
