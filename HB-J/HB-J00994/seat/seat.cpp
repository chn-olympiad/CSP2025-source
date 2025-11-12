#include<iostream>
using namespace std;
int main(){
    int n,m,s;
    int a[10001][10001];
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
            cin>>a[j][i];
        }
    }
    int c=a[0][0];
    for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
            if(i-1<0){
                if(a[j][i]>=a[n][i-1]){
                    s=a[n][i];
                    a[j][i]=a[n][i-1];
                    a[n][i-1]=s;
                }
            }else{
                if(a[j][i]>=a[j-1][i]){
                    s=a[j][i];
                    a[j][i]=a[j-1][i];
                    a[j-1][i]=s;
                }
            }
        }
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
            if(a[j][i]=c){
                cout<<j<<" "<<i;
                break;
            }
        }
    }
    return 0;
}
