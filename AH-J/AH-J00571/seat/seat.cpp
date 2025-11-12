#include<iostream>
using namespace std;
int main(){
  //  freopen("seat.in","r",stdin);
//    freopen("seat.out","w",stdout);
    int n,m,a,b;
    cin>>n>>m;
    cin>>b;
    for(int i=0;i<=n*m-2;i++){
        cin>>a;
        if(b<a){
            cout<<n<<" "<<m;
        }

    }
    return 0;
}
