#include <iostream>
using namespace std;
int n,m;
int b[1000000000000],maxa,c[100000000000],f=0,g=0,cnt=0,k=0,p,q;

int main(){
//    freopen("seat.in","r",std);
//    freopen("seat.out","w",std);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    cnt=b[1];
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=n*m;j++){
            if(b[j]>maxa){
                maxa=b[j];
                f=j;
            }
        }
        c[g]=maxa;
        g++;
        b[f]=0;
    }
    for(int i=1;i<=g;i++){
        if(c[i]==cnt){
           k=i;
        }
    }
    p=k/n+1;
    if(p%2==0){
        q=p*n-k+1;
    }else{
        q=k%n;
    }
    cout<<p<<" "<<q;
    return 0;
}
