#include <iostream>
using namespace std;
int main(){

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int a[20][20],m,n,b[110],c,a1,n1=1,m1=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    a1=b[1];
    for(int i=1;i<n*m;i++){
        for(int j=i+1;j<=n*m;j++){
            if(b[i]<b[j]){
                c=b[i];
                b[i]=b[j];
                b[j]=c;
            }
        }if(b[i]==a1){
            cout<<m1<<" "<<n1;
            break;
        }
        if(m1%2!=0){
            if(n1+1<=n){
                n1++;
            }else if(n1==n&&m1+1<=m){
                m1++;
            }
        }else{
            if(n1-1>=1){
                n1--;
            }else if(m1+1<=m&&n1==1){
                m1++;
            }
        }

    }

    return 0;
}

