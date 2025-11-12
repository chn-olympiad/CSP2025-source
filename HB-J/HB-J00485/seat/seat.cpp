#include<bits/stdc++.h>
using namespace std;
int m,n,a[11][11],q,b[105],bi=0;
int main(){
    cin>>m>>n;
//freopen("seat.in","r"stdin);
//freopen("seat.out","w"stdout);
    for(int i=0;i<m*n;i++){
            cin>>b[i];
    }
    //shuru
    q=b[0];
    for(int i=0;i<m*n-1;i++){
        for(int j=i;j<m*n;j++){
            if(b[j]>b[i])swap(b[j],b[i]);
        }
    }
    //paixu
        for(int i=0;i<m;){
            if(i%2==0){
                for(int j=0;j<n;j++){
                    a[i][j]=b[bi];
                    if(j<n-1)bi++;
          //          cout<<a[i][j]<<" ";
                }
            }
            else if(i%2==1){
                for(int j=n-1;j>=0;j--){
                    a[i][j]=b[bi];
                    if(j!=0)bi++;
                   // cout<<a[i][j]<<" ";
                }
            }
            bi++;
            i++;
           // cout<<endl;
        }

        //moni

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==q){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
return 0;
}
