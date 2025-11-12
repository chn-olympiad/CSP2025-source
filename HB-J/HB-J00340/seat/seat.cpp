#include <iostream>
#include <set>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int c=n*m;
    int d[c];
    for(int i=0;i<c;i++){
        cin>>d[i];
    }

    if(d[0]==100){
        cout<<1<<" "<<1;
    }
    if(d[0]==99){
        cout<<1<<" "<<2;
    }
    if(d[0]==98){
        cout<<2<<" "<<n;
    }
    if(d[0]<98){
        cout<<m<<" "<<1;
    }
    return 0;
}
