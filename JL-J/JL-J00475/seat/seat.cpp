#include <iostream>
using namespace std;
int a[105],b[15][15],c[105],n,m,s=100,flag=0;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        c[a[i]]++;
    }
    for(int i=1;i<=m;i++){
        if (i%2==1){
            for(int j=1;j<=n;j++){
                if (s==a[1]){
                    cout<<i<<" "<<j;
                    flag=1;
                    break;
                }
                else if(c[s]==1){
                    b[i][j] = s;
                }
                else{
                    j--;
                }
                s--;
            }
        }
        else{
            for(int j=n;j>=1;j--){
                if (s==a[1]){
                    cout<<i<<" "<<j;
                    flag=1;
                    break;
                }
                else if(c[s]==1){
                    b[i][j] = s;
                }
                else{
                    j++;
                }
                s--;
            }
        }
        if(flag==1){
            break;
        }
    }
    return 0;
}
