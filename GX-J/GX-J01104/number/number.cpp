#include <iostream>
using namespace std;
int b[123123],a,s,f,e,g=1,h[1111111];
char d[12];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    a=s;
    f=a;

    for(int i=0;i<a;i++){
       e++;
       f=f/10;
       if(f<1)break;
       }
    for(int j=0;j<=e;j++){
        g=g*10;
        h[j]=a/g;
        b[j]=a-h[j]*g;
        }
    g=1;
    for(int q=0;q<e;q++){
    g=g*10;
    h[q]=(b[q+1]-b[q])/g;
    }
    cout<<b[0];
    for(int o=0;o<e;o++){
        cout<<h[o];
    }
    return 0;
}
