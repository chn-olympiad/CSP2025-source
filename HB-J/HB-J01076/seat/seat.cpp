#include <bits/stdc++.h>
using namespace std;
int q[100];
int exch;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,ago;
    cin>>m>>n;
    for(int i=1;i<=m*n;i++){
        cin>>q[i];

    }
    ago=q[1];
    for(int i=1;i<=m*n-1;i++){
        for(int j=1;j<=m*n-1;j++){
            if(q[j]<q[j+1]){
                exch=q[j];
                q[j]=q[j+1];
                q[j+1]=exch;
            }
        }
    }
    for(int i=1;i<=m*n;i++){
        if(q[i]==ago){
            if(i%n==0){
                cout<<i/m<<" ";
            }
            if(i%n!=0){
                cout<<(i/m)+1<<" ";
            }

            if((i/n)%2==1){
                cout<<n-i%n;
               }
            if((i/n)%2==0){
                cout<<i%n;
            }
        }
    }
    return 0;
}
