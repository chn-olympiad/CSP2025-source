#include<bits/stdc++.h>
using namespace std;
char a[100]={0};
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[n][m];
        }
    }
    if(n==1&&m==1)cout<<n<<" "<<m;
    else if(n==1&&m<=10){
        int xl=a[1][1];
        for(int i=0;i<m;i++){
            for(int j=1;j<m;j++){
                int x;
                if(a[n][j-1]<a[n][j]){
                    x=a[n][j];
                    a[n][j]=a[n][j-1];
                    a[n][j-1]=x;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==xl){
                cout<<i<<" "<<j;
                    break;
                }
            }
        }
    }
    return 0;
}
