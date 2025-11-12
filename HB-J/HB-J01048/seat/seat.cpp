#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r;
    cin>>n>>m;
    int a[n*m+1],x[n+1][m+1];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=n*m;j++){
            if(a[j]<a[j+1]){
                int c=a[j];
                a[j]=a[j+1];
                a[j+1]=c;
            }
        }
    }
    for(int i=1,l=1;i<=n;i++){
            if(i%2==0){
                for(int j=m;j>0;j--,l++){
                    x[i][j]=a[l];
                    if(a[l]==r){
                        cout<<i<<" "<<j;
                    }
                }
            }
            else{
                 for(int j=1;j<=m;j++,l++){
            x[i][j]=a[l];
            if(a[l]==r){
                cout<<i<<" "<<j;
            }
        }
            }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
