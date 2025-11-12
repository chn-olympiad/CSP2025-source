#include <iostream>

using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[15][15];
    int b[200];
    int n,m;
    int c;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
        if(i==1){
            c=b[i];
        }
    }
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=m*n;j++){
            if(b[j]<b[j+1]){
                int d=b[j];
                b[j]=b[j+1];
                b[j+1]=d;
            }
        }
    }

    int p;
    for(int i=1;i<=n*m;i++){
        if(b[i]==c){
            p=i;
            break;
        }
    }
    int x,y;
    if(p%n==0){
        x=p/n;
    }
    else{
        x=p/n+1;
    }
    if(x%2==1){
        if(p%n==0){
            y=n;
        }
        else{
            y=p%n;
        }
    }
    else{
        if(p%n==0){
            y=1;
        }
        else{
            y=n-p%n+1;
        }
    }
    cout<<x<<' '<<y;

    return 0;
}
